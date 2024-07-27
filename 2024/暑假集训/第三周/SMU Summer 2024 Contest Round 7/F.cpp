// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<array<int, 2>>> mp;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        mp[x].push_back({y, z});
    }
    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int i = 1; i < 1 << n; i ++) {
        vector<int> t;
        int cv = 0, ok = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) t.push_back(j + 1), cv ++;
        }
        for (auto [y, z] : mp[cv]) {
            int cnt = 0;
            for (auto j : t) {
                if (j <= y) cnt ++;
                if (cnt > z) ok = 1;
            }
        }
        if (!ok) {
            for (auto j : t) {
                dp[i] += dp[i ^ (1 << j - 1)];
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
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