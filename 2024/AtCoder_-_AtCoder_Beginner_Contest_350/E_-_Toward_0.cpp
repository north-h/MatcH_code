/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-20 20:27:14 ms
 *
 * Problem: E - Toward 0
 * Contest: AtCoder - AtCoder Beginner Contest 350
 * URL:     https://atcoder.jp/contests/abc350/tasks/abc350_e
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;
    map<ll, double> dp;
    dp[0] = 0;
    auto dfs = [&](auto self, ll u) -> double {
        if (dp.count(u)) return dp[u];
        double r1 = self(self, u / a) + x;
        double r2 = 0;
        for (int i = 2; i <= 6; i ++) {
            r2 += self(self, u / i);
        }
        r2 = r2 / 5 + 1.2 * y;
        return dp[u] = min(r2, r1);
    };
    cout << lf(7) << dfs(dfs, n) << '\n';
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
