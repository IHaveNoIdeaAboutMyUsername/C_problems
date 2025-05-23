#include <iostream>
#include <vector>
#define ll long long
#define maxn 500005

using namespace std;

template <typename T>
struct ReversedView {
    T& container;
    ReversedView(T& c) : container(c) {}
    auto begin() { return container.rbegin(); }
    auto end() { return container.rend(); }
};

template <typename T>
ReversedView<T> reversed(T& container) {
    return ReversedView<T>(container);
}

struct Quote {
    int Type;
    vector<int> son;
};
Quote T[maxn];
int fa[maxn];
int n;
ll lst[maxn], sum[maxn], ans;
int s[maxn], top;
int depth[maxn];

void dfs(int x) {
    int tmp = 0;
    if (T[x].Type == -1) {
        if (top) { 
            tmp = s[top];
            lst[x] = lst[fa[tmp]] + 1;
            --top;
        }
    }
    else {
        s[++top] = x;
    }

    depth[x] = top; 
    sum[x] = sum[fa[x]] + lst[x]; 
    for (auto i : reversed(T[x].son)) {
        dfs(i);
    }
    if (tmp) {
        s[++top] = tmp;
    }
    else if (T[x].Type == 1) { 
        --top;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        T[i].Type = (c == '(') ? 1 : -1;
    }
    for (int i = 2; i <= n; ++i) {
        cin >> fa[i];
        T[fa[i]].son.push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) {
        ans ^= sum[i] * (ll)i;
    }

    cout << ans;
    return 0;
}