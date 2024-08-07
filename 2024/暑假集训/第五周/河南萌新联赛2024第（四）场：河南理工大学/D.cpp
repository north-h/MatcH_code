// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 1e7 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;

bool judge(int x) {
	for (int i = 2; i * i <= x; i ++) {
		if (x % i == 0) return false;
	}
	return true;
}

void solve() {
	int x; cin >> x;
	if (!judge(x)) cout << "No\n";
	else cout << "Yes\n";
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	cin >> h_h;
	while (h_h--)solve();
	return 0;
}