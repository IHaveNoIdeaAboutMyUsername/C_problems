#include<iostream>
using namespace std;
int v[32005][3], w[32005][3];
int f[32005];
int n, m;
int Only(int x) { return v[x][0]; }
int Two(int x, int y) { return v[x][0] + v[x][y]; }
int All(int x) { return v[x][0] + v[x][1] + v[x][2]; }
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int vv, ww, fa;
		cin >> vv >> ww >> fa;
		if (fa == 0) v[i][0] = vv, w[i][0] = ww;
		else if (v[fa][1] == 0) v[fa][1] = vv, w[fa][1] = ww;
		else v[fa][2] = vv, w[fa][2] = ww;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 0; j--) {
			if (j >= Only(i)) f[j] = max(f[j], f[j - Only(i)] + v[i][0] * w[i][0]);
			if (j >= Two(i, 1)) f[j] = max(f[j], f[j - Two(i, 1)] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);
			if (j >= Two(i, 2)) f[j] = max(f[j], f[j - Two(i, 2)] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);
			if (j >= All(i)) f[j] = max(f[j], f[j - All(i)] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
		}
	}
	cout << f[n] << endl;
	return 0;
}