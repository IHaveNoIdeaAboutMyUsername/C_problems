#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int M = 1e2 + 10;
const int N = 2e5 + 10;
int T, n, m, q;
int cnt[N];
bool ans[M][N], vis[N];
int a[N], pos[N];
void ppp() {
	vector<pair<int, int>> f, g;
	for (int i = 1; i <= n; i++) {
		for (int j = pos[i], p = -0x3f3f3f; j < pos[i + 1]; j++) {
			if (j - p < m) f.emplace_back(i, j), ans[1][a[j]] = 1;
			if (a[j] == 1) p = j;
		}
	}
	for (int i = 2; i <= 100; i++) {
		memset(cnt, 0xff, sizeof(cnt));
		for (auto x : f) {
			int y = a[x.second];
			if (cnt[y] == -1) cnt[y] = x.first;
			else if (cnt[y] != x.first) cnt[y] = 0;
		}
		for (int j = 1; j <= n; j++) {
			for (int k = pos[j]; k < pos[j + 1]; k++) {
				if (~cnt[a[k]] && cnt[a[k]] != j)g.emplace_back(j, k);
			}
		}
		f.clear();
		for (auto x : g)vis[x.second] = 1;
		for (int j = 1; j <= n; j++) {
			for (int k = pos[j], p = -0x3f3f3f; k < pos[j + 1]; k++) {
				if (k - p < m)f.emplace_back(j, k), ans[i][a[k]] = 1;
				if (vis[k])p = k;
			}
		}
		for (auto x : g)vis[x.second] = 0;
		g.clear();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> q;
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			pos[i + 1] = pos[i] + k;
			for (int j = pos[i]; j < pos[i + 1]; j++)
				cin >> a[j];
		}
		ppp();
		int r, c;
		while (q--) {
			cin >> r >> c;
			cout << ans[r][c] << endl;
		}
	}
}