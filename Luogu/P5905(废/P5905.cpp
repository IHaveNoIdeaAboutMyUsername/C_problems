#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 1e9;
struct Edge {
	int v, w, nxt;
}e[10005];
struct Node{
	int dis, id;
	bool operator < (const Node& a) const {
		return dis > a.dis;
	}
	Node(int d, int x) {
		dis = d;
		id = x;
	}
};
int head[5005], cnt = 0, t[5005], vis[5005];
int n, m;
long long h[5005], dis[5005];
void add(int u, int v, int w) {
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
bool spfa(int p) {
	queue<int> q;
	memset(h, 63, sizeof(h));
	h[p] = 0;
	vis[p] = 1;
	q.push(p);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if (h[v] > h[u] + w) {
				h[v] = h[u] + w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
					t[v]++;
					if (t[v] == n + 1) return false;
				}
			}
		}
	}
	return true;
}
void dijkstra(int p) {
	priority_queue<Node> q;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	memset(vis, 0, sizeof(vis));
	dis[p] = 0;
	q.push(Node(0, p));
	while (!q.empty()) {
		int u = q.top().id;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v]) q.push(Node(dis[v], v));
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) add(0, i, 0);
	if (!spfa(0)) {
		cout << -1 << endl;
		return 0;
	}
	for (int u = 1; u <= n; u++) {
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			e[i].w += h[u] - h[v];
		}
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		long long ans = 0;
		for (int j = 1; j <= n; j++) {
			if (dis[j] == INF) 
				ans += j * INF;
			else
				ans += j * (dis[j] + h[j] - h[i]);
		}
		cout << ans << endl;
	}
	return 0;
}