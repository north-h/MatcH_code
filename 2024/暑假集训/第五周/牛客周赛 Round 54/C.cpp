// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	map<int, int> mp;
	for (int i = 1, x; i <= n; i ++) {
		cin >> x;
		mp[x] ++;
	}
	int lst = 0, ans = 0, cnt = INF;
	for (auto [x, y] : mp) {
        cout << x << ' ' << y << '\n';
		if (x - lst == 1) {
			lst = x;
			ans += min(cnt, y);
			cnt = min(cnt, y);
		} else break;
	}
	cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}