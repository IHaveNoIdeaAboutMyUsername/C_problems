#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
1、状态：使用状态(u,d)表示当前位于节点u，时间模k为d，初始状态(1,0)，注意：除法时间时k的倍数(模k为0)
2、优先队列处理：最小堆处理状态，确保每次处理时间是最早的状态
3、时间约束处理：对于每条边(u,v,a_i)，计算到达u的时间t，时候满足 t >= a_i
	如满足，则可以通过
	否则，需要找到下一个满足 t' = d % k 且 t' >= a_i 的时间 t'
4、终点：当前状态(n,0)时，即找到了满足条件的最找离开时间
*/
const int INF = 0x7fffffff;
const int MX = 10005;

struct Edge {
	int v, a;
	Edge() {}
	Edge(int vv, int aa) {
		v = vv;
		a = aa;
	}
};
struct State {
	int tim, u, mod;
	State() {}
	State(int tt, int uu, int md) {
		tim = tt, u = uu, mod = md;
	}
	bool operator>(const State& oth) const {
		return tim > oth.tim;
	}
};
int n, m, k;
vector<vector<Edge> > adj(MX + 1);
vector<vector<int> > dis(MX + 1, vector<int>(MX, INF));
priority_queue<State, vector<State>, greater<State> > pq;

int bfs() {
	pq.emplace(0, 1, 0);
	bool flag = 0;
	int res = -1;

	//cout << "开始搜索" << endl;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int cur_tim = cur.tim;
		int u = cur.u;
		int mod = cur.mod;

		//	cout << cur_tim << " " << u << " " << mod  << " " << "bbbbb" << endl;
		//	cout << "bbbbb\n";
		if (u == n && mod == 0) {
			//	cout << "aaaa\n";
			flag = 1;
			res = cur_tim;
			break;
		}
		//	cout << "111\n";

		if (cur_tim > dis[u][mod]) {
			continue;
		}

		//	cout << "开始循环" << endl;

		for (const auto& edge : adj[u]) {
			int v = edge.v;
			int a = edge.a;
			int new_mod = (mod + 1) % k;

			if (cur_tim >= a) {
				if (dis[v][new_mod] > cur_tim + 1) {
					dis[v][new_mod] = cur_tim + 1;
					pq.emplace(dis[v][new_mod], v, new_mod);
				}
			}
			else {
				int ans = a - cur_tim;
				int m = (ans + k - 1) / k;
				int t = cur_tim + m * k;
				int new_tim = t + 1;
				if (dis[v][new_mod] > new_tim) {
					dis[v][new_mod] = new_tim;
					pq.emplace(new_tim, v, new_mod);
				}
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, a;
		cin >> u >> v >> a;
		adj[u].emplace_back(v, a);
	}
	cout << bfs() << "\n";
	return 0;
}