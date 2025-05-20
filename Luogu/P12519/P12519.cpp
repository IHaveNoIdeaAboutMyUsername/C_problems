#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
double rt2(double x) {
	int y;
	double z;
	x *= 100, y = x;
	z = y / 100.0;
	return z;
}
struct node {
	double a, b, c, rks;
}a[N];
double b[6], tb[6], m;
int n;
bool check(int k) {
	double rks = 0;
	memcpy(b, tb, sizeof tb);
	for (int i = 1; i <= n; i++) {
		double acc = min(100.0, a[i].a + (k - 1) * a[i].b);
		if (acc <= 70) a[i].rks = 0;
		else {
			a[i].rks = rt2((acc - 55.0) / 45.0);
			a[i].rks = rt2(a[i].rks * a[i].rks * a[i].c);
		}
		if (a[i].rks > b[1]) b[1] = a[i].rks;

		if (acc == 100.0) b[0] = max(b[0], a[i].rks);
		double rks = rt2((b[0] + b[1] + b[2] + b[3] + b[4]) / 5.0);
		if (rks >= m) return true;
		for (int j = 1; j <= 3; j++) {
			if (b[j] > b[j + 1]) swap(b[j], b[j + 1]);
			else break;
		}
	}
	return false;
}
int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i].a >> a[i].b >> a[i].c;
	cin >> b[1] >> b[2] >> b[3] >> b[4] >> b[0];
	sort(b + 1, b + 5);
	for (int i = 0; i <= 4; i++) tb[i] = b[i];

	int l = 0, r = 10010, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}