#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n;
int dp[1005][2], f[1005][2];

map<string, int> m;
vector<int> E[1005];

void dfs(int now) {
	dp[now][0] = 0;
	dp[now][1] = 1;
	for (auto i : E[now]) {
		dfs(i);
		dp[now][0] += max(dp[i][1], dp[i][0]);
		if (dp[i][1] == dp[i][0]) f[now][0] = 0;
		else if ((!f[i][1] && dp[i][1] > dp[i][0]) || (!f[i][0] && dp[i][0] > dp[i][1])) f[now][0] = 0;

		dp[now][1] += dp[i][0];
		if (!f[i][0]) f[now][1] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n && n) {
		string name1, name2;
		m.clear();
		for (int i = 0; i <= n; i++) E[i].clear();
		memset(f, 1, sizeof(f));
		int cnt = 1;
		cin >> name1;
		m[name1] = cnt;
		cnt++;
		E[0].push_back(m[name1]);
		for (int i = 1; i < n; i++) {
			cin >> name1 >> name2;
			if (m[name1] == 0) m[name1] = cnt, cnt++;
			if (m[name2] == 0) m[name2] = cnt, cnt++;
			E[m[name2]].push_back(m[name1]);
		}
		dfs(0);
		cout << dp[0][0] << " ";
		cout << (f[0][0] ? "Yes" : "No") << endl;
	}
	return 0;
}
/*
6
Jason
Jack Jason
Joe Jack
Jill Jason
John Jack
Jim Jill
2
Ming
Cho Ming
0
*/