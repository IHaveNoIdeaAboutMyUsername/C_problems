#include<algorithm>
#include<iostream>
using namespace std;
int fa[1005];
struct Edge {
	int u, v, w;
}e[10005];
int len, n, m, k;
void Add_edge(int u, int v, int w) {
	++len;
	e[len].u = u;
	e[len].v = v;
	e[len].w = w;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
void Kruskal() {
	int tot = 0, ans = 0;
	for (int i = 1; i <= m; i++) {
		int x2 = find(e[i].u);
		int y2 = find(e[i].v);
		if (x2 != y2) {
			Merge(x2, y2);
			tot++;
			ans += e[i].w;
		}
		if (tot >= n - k) {
			cout << ans << endl;
			return;
		}
	}
	cout << "No Answer" << endl;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Add_edge(x, y, z);
	}
	sort(e + 1, e + m + 1, cmp);
	Kruskal();
	return 0;
}