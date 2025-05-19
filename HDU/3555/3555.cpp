#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 30;
int num[N];
ll n, dp[N][2], z[N];
ll dfs(int now, bool flag, bool iflimited) {
	if (!now) return 0;
	if (!iflimited && dp[now][flag] != -1)
		return dp[now][flag];
	int maxl = iflimited ? num[now] : 9;
	ll ans = 0;
	for (int i = 0; i <= maxl; i++) {
		if (flag && i == 9) ans += iflimited ? n % z[now - 1] + 1 : z[now - 1];
		else ans += dfs(now - 1, i == 4, iflimited && i == maxl);
	}
	if (!iflimited) dp[now][flag] = ans;
	return ans;
}
ll solve(int x) {
	int pos = 0;
	while (x) {
		num[++pos] = x % 10;
		x /= 10;
	}
	return dfs(pos, 0, 1);
}
int main() {
	memset(dp, -1, sizeof(dp));
	z[0] = 1;
	for (int i = 1; i < N; i++) z[i] = z[i - 1] * 10;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << solve(n) << endl;
	}
}