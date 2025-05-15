#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

#define CLR(a) memset(a,0,sizeof(a))
#define f(i, j, k) for(int i = j; i <= k; ++i)
#define gd(i, j, k) for(int i = j; i >= k; --i)

using namespace std;

constexpr int MAXN = 9999;
// MAXN ��һλ����������
constexpr int MAXSIZE = 10024;
// MAXSIZE ��λ��
constexpr int DLEN = 4;

long long cnt = 0;
// DLEN ��¼ѹ��λ
struct Big {
    int a[MAXSIZE], len;
    bool flag;  // ��Ƿ���'-'

    Big() {
        len = 1;
        memset(a, 0, sizeof a);
        flag = false;
    }

    Big(const int);
    Big(const char*);
    Big(const Big&);
    Big& operator=(const Big&);
    Big operator+(const Big&) const;
    Big operator-(const Big&) const;
    Big operator*(const Big&) const;
    Big operator/(const int&) const;
    // TODO: Big / Big;
    Big operator^(const int&) const;
    // TODO: Big ^ Big;

    // TODO: Big λ����;

    Big operator%(const Big&) const;
    // TODO: Big ^ Big;
    bool operator<(const Big&) const;
    bool operator<(const int& t) const;
    void print() const;
};

Big::Big(const int b) {
    int c, d = b;
    len = 0;
    // memset(a,0,sizeof a);
    CLR(a);
    flag = false;
    while (d > MAXN) {
        c = d - (d / (MAXN + 1) * (MAXN + 1));
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}

Big::Big(const char* s) {
    int t, k, index, l;
    CLR(a);
    l = strlen(s);
    len = l / DLEN;
    if (l % DLEN) ++len;
    index = 0;
    for (int i = l - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0) k = 0;
        f(j, k, i) t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}

Big::Big(const Big& T) : len(T.len) {
    CLR(a);
    f(i, 0, len) a[i] = T.a[i];
    // TODO:���ش˴���
}

Big& Big::operator=(const Big& T) {
    CLR(a);
    len = T.len;
    f(i, 0, len) a[i] = T.a[i];
    return *this;
}

Big Big::operator+(const Big& T) const {
    Big t(*this);
    int big = len;
    if (T.len > len) big = T.len;
    f(i, 0, big) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN) {
            ++t.a[i + 1];
            t.a[i] -= MAXN + 1;
        }
    }
    if (t.a[big])
        t.len = big + 1;
    else
        t.len = big;
    return t;
}

Big Big::operator-(const Big& T) const {
    int big;
    bool ctf;
    Big t1, t2;
    if (*this < T) {
        t1 = T;
        t2 = *this;
        ctf = true;
    }
    else {
        t1 = *this;
        t2 = T;
        ctf = false;
    }
    big = t1.len;
    int j = 0;
    f(i, 0, big) {
        if (t1.a[i] < t2.a[i]) {
            j = i + 1;
            while (t1.a[j] == 0) ++j;
            --t1.a[j--];
            // WTF?
            while (j > i) t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while (t1.len > 1 && t1.a[t1.len - 1] == 0) {
        --t1.len;
        --big;
    }
    if (ctf) t1.a[big - 1] = -t1.a[big - 1];
    return t1;
}

Big Big::operator*(const Big& T) const {
    Big res;
    res.len = len + T.len; // ��ʼ���������Ϊ������ֵ
    long long temp; // ʹ�ø�����������ͷ�ֹ�м����
    int up;

    // ���ѭ��������ǰ�����ÿһλ
    f(i, 0, len - 1) {
        up = 0;
        // �ڲ�ѭ���������������ÿһλ

        f(j, 0, T.len - 1) {
            // ����˻������ϵ�ǰλ�õ�ֵ�ͽ�λ
            temp = (long long)a[i] * T.a[j] + res.a[i + j] + up;
            // ���㵱ǰλ��ֵ���µĽ�λ
            res.a[i + j] = temp % (MAXN + 1);
            up = temp / (MAXN + 1);
        }
        // ����ʣ���λ�����õ���λ��
        if (up > 0) {
            res.a[i + T.len] += up; // ע�������� += ����ֱ�Ӹ�ֵ
            // ����Ƿ���Ҫ��չ�������
            if (i + T.len >= res.len && res.a[i + T.len] != 0) {
                res.len = i + T.len + 1;
            }
        }
    }

    // ȥ��ǰ����
    while (res.len > 1 && res.a[res.len - 1] == 0) {
        --res.len;
    }

    return res;
}

Big Big::operator/(const int& b) const {
    Big res;
    int down = 0;
    gd(i, len - 1, 0) {
        res.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - res.a[i] * b;
    }
    res.len = len;
    while (res.len > 1 && res.a[res.len - 1] == 0) --res.len;
    return res;
}

Big Big::operator%(const Big& b) const {
    Big remainder = *this;
    if (remainder < b) return remainder;

    // �����̵����λλ��
    int shift = remainder.len - b.len;
    Big base = b;
    base = base * Big(MAXN + 1).operator^(shift); // ���Ƶ��������λ

    while (!(remainder < b)) {
        while (!(remainder < base)) {
            remainder = remainder - base;
        }
        base = base / (MAXN + 1); // ����һλ
    }

    return remainder;
}
Big Big::operator^(const int& n) const {
    Big t(n), res(1);
    int y = n;
    while (y) {
        if (y & 1) res = res * t;
        t = t * t;
        y >>= 1;
    }
    return res;
}

bool Big::operator<(const Big& T) const {
    int ln;
    if (len < T.len) return true;
    if (len == T.len) {
        ln = len - 1;
        while (ln >= 0 && a[ln] == T.a[ln]) --ln;
        if (ln >= 0 && a[ln] < T.a[ln]) return true;
        return false;
    }
    return false;
}

bool Big::operator<(const int& t) const {
    Big tee(t);
    return *this < tee;
}

void Big::print() const {
    printf("%d", a[len - 1]);
    gd(i, len - 2, 0) { printf("%04d", a[i]); }
}

void print(const Big& s) {
    int len = s.len;
    printf("%d", s.a[len - 1]);
    gd(i, len - 2, 0) { printf("%04d", s.a[i]); }
}

int main() {
    int p;
    cin >> p;
    Big ans = 1, m = 2;
    cout << int(log10(2) * p + 1) << endl;
    cout << 1 << endl;

    // 修复点1: 先计算模数 k = 10^500
    Big k = 1;
    f(i, 1, 500) k = k * 10;  // 正确初始化 k 为 10^500

    // 修复点2: 使用正确的模数进行快速幂运算
    for (; p; p >>= 1) {
        if (p & 1) {
            ans = ans * m;
            ans = ans % k;  // 使用初始化好的大模数
        }
        m = m * m;
        m = m % k;          // 使用初始化好的大模数
    }
    cout << 2 << endl;
    ans = ans - 1;
    int sze = 500 - ans.len;
    int t = 0;
    if (sze > 0) {
        f(i, 1, sze) {
            cout << 0;
            if (i % 50 == 0) cout << endl;
        }
        t = sze;
    }
    cout << 3 << endl;
    for (auto i = ans.len - 1; i >= 0 && t <= 500; --i) {
        ++t;
        cout << ans.a[i];
        if (t % 50 == 0) cout << endl;
    }
    return 0;
}