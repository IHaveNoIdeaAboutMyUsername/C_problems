#include<iostream>
#include<stdio.h>
using namespace std;
int A[1005], B[1005];
int n;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	A[0] = 1;
	B[0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 100; j++)
			B[j] *= i;
		for (int j = 0; j < 100; j++)
			if (B[j] > 9) {
				B[j + 1] += B[j] / 10;
				B[j] %= 10;
			}
		for (int j = 0; j < 100; j++) {
			A[j] += B[j];
			if (A[j] > 9) {
				A[j + 1] += A[j] / 10;
				A[j] %= 10;
			}
		}
	}
	bool flag = 1;
	for (int i = 100; i >= 0; i--) {
		if (A[i] != 0) flag = 0;
		if (!flag) cout << A[i];
	}
	return 0;
}
