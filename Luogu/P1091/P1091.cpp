#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 7, INF = 1e9;
int a[N], f1[N], f2[N], g[N], len, ans = -INF;

int main() { 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(g + 1, g + len + 1, a[i]) - g;
		f1[i] = pos;
		g[pos] = a[i];
		len = max(len, pos);
	}
	/*for (int i = 1; i <= n; i++) cout << f1[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++) cout << g[i] << ' ';
	cout << endl;*/
	len = 0;
	memset(g, 0, sizeof g);
	for (int i = n; i >= 1; i--) {
		int pos = lower_bound(g + 1, g + len + 1, a[i]) - g;
		f2[i] = pos;
		g[pos] = a[i];
		len = max(len, pos);
	}
	/*for (int i = 1; i <= n; i++) cout << f2[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++) cout << g[i] << ' ';
	cout << endl;*/
	for (int i = 1; i <= n; i++) ans = max(ans, f1[i] + f2[i] - 1);
	cout << n - ans << endl;

	return 0;
}