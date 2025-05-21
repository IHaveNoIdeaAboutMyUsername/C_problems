#include<iostream>
#include<vector>
using namespace std;
struct Flower {
	vector<int> nxt;
	int beauty;
}flowers[16005];
bool vis1[16005];
int n, f[16005], ans = -1e9 - 7;
void put() {
	for (int i = 1; i <= n; i++) cout << f[i] << "\t";
	cout << ans << "\t";
	cout << endl;
}
void s(int pos) {
	f[pos] = flowers[pos].beauty;
	vis1[pos] = 1;
//	put();
	for (auto i : flowers[pos].nxt) {
		if (!vis1[i]) {
//			cout << pos << " " << i << endl;
			s(i);
//			cout << pos << ":" << f[pos] << " " << f[i] << " " << f[i] + f[pos] << endl;
			if (f[i] + f[pos] > f[pos]) f[pos] = max(f[i] + f[pos], f[pos]);
//			put();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> flowers[i].beauty;
	for(int i=1;i<n;i++) {
		int a, b;
		cin >> a >> b;
		flowers[a].nxt.push_back(b);
		flowers[b].nxt.push_back(a);
	}
	s(1);
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}