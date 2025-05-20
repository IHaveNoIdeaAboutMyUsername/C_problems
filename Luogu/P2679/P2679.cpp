#include<iostream>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, k;
bool choose = true;
char a[1005], b[1005];
int f[2][205][205][2];
void ff() {
	f[0][0][0][0] = f[1][0][0][0] = 1;
	for(int i=1;i<=n;i++,choose^=1)
		for (int j = 1; j <= m; j++)
			for (int l = 1; l <= k; l++)
				if (a[i] == b[j]) {
					f[choose][j][l][0] = (f[choose ^ 1][j][l][0] + f[choose ^ 1][j][l][1]) % MOD;
					f[choose][j][l][1] = (f[choose ^ 1][j - 1][l][1] + (f[choose ^ 1][j - 1][l - 1][0] + f[choose ^ 1][j - 1][l - 1][1]) % MOD) % MOD;
				}
				else {
					f[choose][j][l][0] = (f[choose ^ 1][j][l][0] + f[choose ^ 1][j][l][1]) % MOD;
					f[choose][j][l][1] = 0;
				}
}
int main() {
	cin >> n >> m >> k;
	scanf("%s%s", a + 1, b + 1);
	ff();
	cout << (f[n & 1][m][k][0] + f[n & 1][m][k][1]) % MOD << endl;
	return 0;
}