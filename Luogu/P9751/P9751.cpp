//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include<set>
//using namespace std;
//
//struct Edge {
//   vector<pair<int, int>> v;
//};
//int n, m, k;
//Edge e[20005];
//int ans = 1e9 + 7;
//bool vis[20005][105];
//
//bool bfs2() {
//    queue<pair<int, int>> q;
//    memset(vis, 0, sizeof(vis));
//    q.push({ 1, 0 });
//    vis[1][0] = true;
//    while (!q.empty()) {
//        pair<int, int> front = q.front();
//        int now = front.first;
//        int t = front.second;
//        q.pop();
//        if (now == n && t % k == 0) {
//            return true; //使这里直接比较出最小的t，在路径里选出最大的a_i确定最小的出发时间。
//        }
//        for (auto& edge : e[now].v) {
//            int nxt = edge.first, limit = edge.second;
//            if (/*limit <= t &&*/ !vis[nxt][(t + 1) % k]) {
//                vis[nxt][(t + 1) % k] = true;
//                q.push({ nxt, t + 1 });
//            }
//        }
//    }
//    return false;
//}
//
//int bfs() {
//   queue<pair<int, int>> q;
//   if (bfs2()) {
//       int begin = 0;
//       while (1) {
//           //       cout << begin << endl;
//           memset(vis, 0, sizeof(vis));
//           q.push({ 1, begin * k });
//           vis[1][0] = true;
//           while (!q.empty()) {
//               pair<int, int> front = q.front();
//               int now = front.first;
//               int t = front.second;
//               q.pop();
//               if (now == n && t % k == 0) {
//                   ans = t;
//                   return ans;
//               }
//               for (auto& edge : e[now].v) {
//                   int nxt = edge.first, limit = edge.second;
//                   if (limit <= t && !vis[nxt][(t + 1) % k]) {
//                       vis[nxt][(t + 1) % k] = true;
//                       q.push({ nxt, t + 1 });
//                   }
//               }
//           }
//           begin++;
//       }
//   }
//   return -1;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0), cout.tie(0);
//    cin >> n >> m >> k;
//    for (int i = 1; i <= m; i++) {
//        int u, v, t;
//        cin >> u >> v >> t;
//        e[u].v.emplace_back(v, t);
//    }
//    cout << bfs();
//    return 0;
//}
