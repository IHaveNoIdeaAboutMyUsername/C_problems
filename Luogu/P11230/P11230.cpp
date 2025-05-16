//#include <iostream>
//#include <vector>
//using namespace std;
//const int MAXN = 2e5 + 10;
//const int MAXM = 1e2 + 10;
//int T, n, m, q; int cnt[MAXN]; bool ans[MAXM][MAXN];
//int a[MAXN]; bool vis[MAXN]; int pos[MAXN];
//void init() {
//	vector<pair<int, int>> f, g;
//	for (int i = 1; i <= n; i++) {
//		for (int j = pos[i], p = -1e9; j < pos[i + 1]; j++) {
//			if (j - p < m) f.emplace_back(i, j), ans[1][a[j]] = 1;
//			if (a[j] == 1) p = j;
//		}
//	}
//	for (int t = 2; t <= 100; t++) {
//		memset(cnt, 0xff, sizeof cnt);
//		for (pair<int, int> x : f) {
//			int y = a[x.second];
//			if (cnt[y] == -1) cnt[y] = x.first;
//			else if (cnt[y] != x.first) cnt[y] = 0;
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = pos[i]; j < pos[i + 1]; j++) {
//				if (~cnt[a[j]] && cnt[a[j]] != i) g.emplace_back(i, j);
//			}
//		}
//		f.clear();
//		for (pair<int, int> x : g) vis[x.second] = 1;
//		for (int i = 1; i <= n; i++) {
//			for (int j = pos[i], p = -1e9; j < pos[i + 1]; j++) {
//				if (j - p < m) f.emplace_back(i, j), ans[t][a[j]] = 1;
//				if (vis[j]) p = j;
//			}
//		}
//		for (pair<int, int> x : g) vis[x.second] = 0;
//		g.clear();
//	}
//}
//int main() {
//	for (cin >> T; T--; ) {
//		cin >> n >> m >> q;
//		memset(ans, 0, sizeof ans);
//		memset(vis, 0, sizeof vis);
//		for (int i = 1, k; i <= n; i++) {
//			cin >> k;
//			pos[i + 1] = pos[i] + k;
//			for (int j = pos[i]; j < pos[i + 1]; j++)cin >> a[j];
//		}
//		init();
//		int r, c;
//		while (q--) {
//			cin >> r >> c;
//			printf("%d\n", ans[r][c]);
//		}
//	}
//}
