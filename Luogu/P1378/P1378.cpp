#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double pi = 3.1415926;
int n;
int X1, X2, Y1, Y2;
double ans;
pair<int, int> oil[10];
double r[10];
bool spread[10];
void f(int pos, double area) {
	if (pos == n + 1) {
		ans = max(ans, area);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!spread[i]) {
			int tmp = 0;
			for (int j = 1; j <= n; j++) {
				if (spread[j] && r[j] >= sqrt((oil[i].first - oil[j].first) * (oil[i].first - oil[j].first) + (oil[i].second - oil[j].second) * (oil[i].second - oil[j].second))) {
					tmp = 1;
					spread[i] = 1;
					f(pos + 1, area);
					spread[i] = 0;
				}
			}
			if (tmp == 1) continue;
			spread[i] = 1;
			r[i] = min(abs(oil[i].first - X1), abs(oil[i].first - X2));
			r[i] = min(r[i], (double)min(abs(oil[i].second - Y1), abs(oil[i].second - Y2)));
			for (int j = 1; j <= n; j++) {
				if (i != j && spread[j]) {
					double d = sqrt((oil[i].first - oil[j].first) * (oil[i].first - oil[j].first) + (oil[i].second - oil[j].second) * (oil[i].second - oil[j].second));
					r[i] = min(r[i], d - r[j]);
				}
			}
			f(pos + 1, area + pi * r[i] * r[i]);
			r[i] = 0;
			spread[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	cin >> X1 >> Y1 >> X2 >> Y2;
	X1 += 1000;
	X2 += 1000;
	Y1 += 1000;
	Y2 += 1000;
	for (int i = 1; i <= n; i++) {
		cin >> oil[i].first >> oil[i].second;
		oil[i].first += 1000;
		oil[i].second += 1000;
	}
	f(1, 0.0);
	ans = abs(X1 - X2) * abs(Y1 - Y2) - ans;
	int ansns = (int)(ans + 0.5);
	cout << ansns << endl;
	return 0;
}