#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
 
using namespace std;
int a, b, c;
static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
//	freopen("P9750_2.in", "r", stdin);
	int T, M;
	cin >> T >> M;
	while (T--) {
		cin >> a >> b >> c;
		int delta = b * b - 4 * a * c;
		if (delta < 0) {
			cout << "NO" << endl;
			continue;
		}
		if (a < 0)
			a = -a, b = -b, c = -c;
		int a2, b2;
		b2 = -b, a2 = 2 * a;
	//	cout << b2 << " " << a2 << " " << delta << endl;
		if (((int)sqrt(delta) * 10) * ((int)sqrt(delta) * 10) == delta * 100) {
			b2 += sqrt(delta);
			//	cout << (10 * b2 / (2 * a2)) * 2 * a2 << " " << b2 << endl;
			if ((10 * b2 / (2 * a2)) * 2 * a2 == 10 * b2) cout << b2 / a2;
			else cout << (b2 / gcd(abs(a2), abs(b2))) << "/" << (a2 / gcd(abs(a2), abs(b2)));
		}
		else {
			if ((10 * b2 / (2 * a2)) * 2 * a2 == 10 * b2 && b != 0) cout << b2 / a2 << "+";
			else if (b != 0) cout << (b2 / gcd(abs(a2), abs(b2))) << "/" << (a2 / gcd(abs(a2), abs(b2))) << "+";
			int tmp = 1;
			for (int i = 2; i * i <= delta; i++) {
				while (delta % (i * i) == 0) {
					tmp *= i;
					delta /= i * i;
				}
			}
			if (tmp / gcd(abs(a2), abs(tmp)) != 1) 
				cout << (tmp / gcd(abs(a2), abs(tmp))) << "*";
			cout << "sqrt(" << delta << ")";
			if (a2 / gcd(abs(a2), abs(tmp)) != 1)
				cout << "/" << (a2 / gcd(abs(a2), abs(tmp)));
//			cout << tmp / a2 << endl;

		}

		cout << endl;
	}
	return 0;
}