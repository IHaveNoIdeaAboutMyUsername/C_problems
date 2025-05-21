#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
	int u, v, w;
}edge[200005];
int fa[5005], tot, n, m, ans, eu, ev, cnt;
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
int find(int x)
{
	while (x != fa[x])
	{
		fa[x] = fa[fa[x]];
		x = fa[x];
	}
	return x;
}
void kruskal() {
	sort(edge, edge + m, cmp);
	for (int i = 0; i < m; i++) {
		eu = find(edge[i].u);
		ev = find(edge[i].v);
		if (eu == ev) continue;
		fa[eu] = ev;
		ans += edge[i].w;
		if (++cnt == n - 1) break;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	kruskal();
	if (cnt + 1 == n) cout << ans << endl;
	else cout << "orz" << endl;
	return 0;
}