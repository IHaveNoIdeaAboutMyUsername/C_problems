#include<iostream>
#include<cstring>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
const int N = 1e6 + 1;
char c[N];
int a1, a2, len, sum;
int quote, orx[N], andx[N];
int ory[N], andy[N];
void init() {
	quote = 0;
	for (int i = 1; i <= len; i++) {
		if (c[i] == '(') quote++;
		else if (c[i] == ')') quote--;
		else if (c[i] == '|') ory[quote] = i;
		else if (c[i] == '&') andy[quote] = i;
		orx[i] = ory[quote];
		andx[i] = andy[quote];
	}
}
int f(int l, int r) {
	
//	print(l,r,orx,andx);
	if (orx[r] >= l) {
		int lft = f(l, orx[r] - 1);
		if (lft == 1) {
			a1++;
			return 1;
		}
		else {
			int rit = f(orx[r] + 1, r);
			return (lft | rit);
		}
	}
	if (andx[r] >= l) {
		int lft = f(l, andx[r] - 1);
		if (lft == 0) {
			a2++;
			return 0;
		}
		else {
			int rit = f(andx[r] + 1, r);
			return (lft & rit);
		}
	}
	if (c[l] == '(' && c[r] == ')') return f(l + 1, r - 1);
	else return c[l] - '0';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	scanf("%s", c + 1);
	len = strlen(c + 1);
	init();
	sum = f(1, len);
	cout << sum << "\n" << a2 << " " << a1 << endl;
	return 0;
}