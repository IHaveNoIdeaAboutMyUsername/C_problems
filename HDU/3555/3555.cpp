#include<iostream>
#include<cstdio>

using namespace std;
#define read(st,en,a) for(int II=st;II<=en;II++) cin>>a[II]
#define up(s,e,i) for(int i=s;i<=e;i++)
#define down(s,e,i) for(int i=s;i>=e;i--) 
#define all(x) x.begin(),x.end()
#define endl '\n' 
#define ll long long
//·¨2
namespace Main
{
    ll f[25][10][2], g[25][10][2];
    void solve()
    {
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;

        up(0, n, i) up(0, 9, j) up(0, 1, k) f[i][j][k] = 0, g[i][j][k] = 0;

        f[0][0][1] = 1;
        g[0][0][1] = 0;
        up(1, n, i)
        {
            up(0, 9, x) up(0, 9, y)
            {
                g[i][y][0] += g[i - 1][x][0];

                if (y < s[i] - '0') g[i][y][0] += g[i - 1][x][1];
                else if (y == s[i] - '0') g[i][y][1] += g[i - 1][x][1];

                if (x == 4 && y == 9)
                {
                    g[i][y][0] += f[i - 1][x][0];
                    if (y < s[i] - '0') g[i][y][0] += f[i - 1][x][1];
                    else if (y == s[i] - '0') g[i][y][1] += f[i - 1][x][1];
                }
                else
                {
                    f[i][y][0] += f[i - 1][x][0];
                    if (y < s[i] - '0') f[i][y][0] += f[i - 1][x][1];
                    else if (y == s[i] - '0') f[i][y][1] += f[i - 1][x][1];
                }
            }
        }
        ll ans = 0;
        up(0, 9, i) ans += g[n][i][0] + g[n][i][1];
        cout << ans << endl;
    }
    void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int _; cin >> _; while (_--)solve();
    }
};

//·¨1
const int N = 30;
ll num[N];
ll n, dp[N][2], z[N];
ll dfs(int now, bool flag, bool iflimited) {
	if (!now) return 0;
	if (!iflimited && dp[now][flag] != -1)
		return dp[now][flag];
	ll maxl = iflimited ? num[now] : 9;
	ll ans = 0;
	for (ll i = 0; i <= maxl; i++) {
		if (flag && i == 9) ans += iflimited ? n % z[now - 1] + 1 : z[now - 1];
		else ans += dfs(now - 1, i == 4, iflimited && i == maxl);
	}
	if (!iflimited) dp[now][flag] = ans;
	return ans;
}
ll solve(ll x) {
	ll pos = 0;
	while (x) {
		num[++pos] = x % 10;
		x /= 10;
	}
	return dfs(pos, 0, 1);
}

int main() {
    //·¨2
    //Main::main();

	memset(dp, -1, sizeof(dp));
	z[0] = 1;
	for (int i = 1; i < N; i++) z[i] = z[i - 1] * 10;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << solve(n) << endl;
	}
    return 0;
}