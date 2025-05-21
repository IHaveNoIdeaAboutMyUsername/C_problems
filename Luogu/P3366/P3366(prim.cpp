//#include<iostream>
//using namespace std;
//int read()
//{
//	int x = 0, f = 1; char c = getchar();
//	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
//	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
//	return x * f;
//}
//const int N = 5005, M = 2e5 + 10;
//struct Edge {
//	int v, w, nxt;
//}e[M << 1];
//int head[N], tot, n, m, ans, cnt, dis[N], now = 1;
//bool vis[N];
//void add(int u, int v, int w) {
//	e[++tot].v = v;
//	e[tot].w = w;
//	e[tot].nxt = head[u];
//	head[u] = cnt;
//}
//void init() {
//	n = read(), m = read();
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;
//		u = read(), v = read(), w = read();
//		add(u, v, w);
//		add(v, u, w);
//	}
//}
//int prim() {
//	for (int i = 2; i <= n; i = e[i].nxt)
//		dis[i] = 1e9;
//	for (int i = head[1]; i; i = e[i].nxt) 
//		dis[e[i].v] = min(dis[e[i].v], e[i].w);
//	while (++tot < n) {
//		int minn = 1e9;
//		vis[now] = 1;
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i] && dis[i] < minn) {
//				minn = dis[i];
//				now = i;
//			}
//		}
//		ans += dis[now];
//		for (int i = head[now]; i; i = e[i].nxt) 
//			if (!vis[e[i].v] && dis[e[i].v] > e[i].w) 
//				dis[e[i].v] = e[i].w;
//	}
//	return ans;
//}
//int main() {
//	init();
//	cout << prim() << endl;
//	return 0;
//}