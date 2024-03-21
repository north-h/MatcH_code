// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
    }
	vector<int> z(n + 1);
	z[1] = 1;
	for (int i = 2; i <= n; i ++) {
		int x = i;
		int num = 1;
		for (int j = 2; j * j <= x; j ++) {
			if (x % j != 0) continue;
			int c = 0;
			while (x % j == 0) x /= j, c ++;
			num *= (c + 1);
		}
		if (x > 1) num *= 2;
		// debug2(i, num);
		z[i] = num;
	}
	int ans = 0;
	auto dfs = [&](auto self, int u, int f) -> int {
		int res = z[u];
		for (auto i : g[u]) {
			if (i == f) continue;
			int x = self(self, i, u);
			if (x >= k) {
				ans ++;
				return x;
			}
			res *= x;
			if (res >= k) {
				ans ++;
				return res;
			}
			
		}
		if (res >= k) ans ++;
		return res;
	};
	dfs(dfs, 1, 0);
	cout << ans << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}