#include<iostream>
using namespace std;
typedef long long ll;
const ll inf = 2e9, f[10] = { 6,2,5,5,4,5,6,3,7,6 };
ll i, ans;
void dfs(ll gz, ll x) {
	if (gz > i)return;
	if (gz == i)return ans = min(ans, x), void();
	for (ll i = 0; i <= 9; i++) {
		if (i == 0 && gz == 0)continue;
		dfs(gz + f[i], x * 10 + i);
	}
}
int main() {
	for (i = 1; i <= 40; i++) {
		ans = inf;
		dfs(0, 0);
		cout << i << "--" << ans << '\n';
	}
}