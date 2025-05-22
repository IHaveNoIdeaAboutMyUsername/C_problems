#include <iostream>
using namespace std;
constexpr int MAXN = 3010;
int n, W, w[MAXN], v[MAXN], f[MAXN];
int a[MAXN][MAXN], an;
int main() {
    cin >> W >> n;
    for (int i = 1; i <= n; i++){
        int p;
        cin >> w[i] >> v[i] >> p;
        an = max(an, p);
        a[p][++a[p][0]] = i;
    }
    //for (int i = 1; i <= an; i++) {
    //    cout << i << " ";
    //    for (int j = 0; j <= a[i][0]; j++)
    //        cout << a[i][j] << " ";
    //    cout << endl;
    //}
    for (int p = 1; p <= an; p++)
        for (int l = W; l >= 0; l--)
            for (int i = 1; i <= a[p][0]; i++)
                if(l>=w[a[p][i]])
                    f[l] = max(f[l - w[a[p][i]]] + v[a[p][i]], f[l]);
    cout << f[W];
    return 0;
}