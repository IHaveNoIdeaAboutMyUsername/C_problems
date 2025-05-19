#include<iostream>
#include<cstdio>
using namespace std;
int dp[15][15];
int num[15];
void set() {
	dp[0][0] = 1;
	for (int i = 1; i <= 9; i++) for (int j = 0; j <= 9; j++) {
		if (j == 4) dp[i][j] = 0;
		else for (int k = 0; k <= 9; k++) {
			if (k == 2 && j == 6) continue;
			dp[i][j] += dp[i - 1][k];
		}
	}
}
int get(int x) {
	int ans = 0, cnt = 0;
	while (x)
		num[++cnt] = x % 10, x /= 10;
	num[cnt + 1] = 0;
	for (int i = cnt; i >= 1; i--) {
		for (int j = 0; j < num[i]; j++) 
			if (j == 4 || (j == 2 && num[i + 1] == 6)) continue;
			else ans += dp[i][j];
		if (num[i] == 4 || (num[i] == 2 && num[i + 1] == 6)) {
			ans--;
			break;
		}
	}
	return ans;
}
int main() {
	int n, m;
	memset(dp, 0, sizeof(dp));
	set();
	while (cin >> n >> m && m + n) {
		cout << get(m) - get(n - 1) << endl;
	}
	return 0;
}