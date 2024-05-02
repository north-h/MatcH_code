/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-02 15:32:24 ms
 *
 * Problem: C. Minimizing the Sum
 * Contest: Codeforces - Educational Codeforces Round 165 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1969/problem/C
 * MemoryL: 256 MB
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
    int n, m; cin >> n >> m;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            ll mn = a[i];
            dp[i][j] = dp[i - 1][j] + a[i];
            for (int k = 1; k <= j && i - k - 1 >= 0; k ++) {
                mn = min(mn, a[i - k]);
                // if (i == 0) dp[i][j] = dp[i - 1][j] + a[i];
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + mn * (k + 1));
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         dp[i][j] = dp[i - 1][j] + a[i];
    //         ll mn = a[i], sum = a[i];
    //         for (int k = 1; k <= j && i - k - 1 >= 0; k++) {
    //             mn = min(mn, a[i - k]);
    //             dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + mn * (k + 1));
    //         }
    //     }
    // }
    cout << *min(dp[n].begin(), dp[n].end()) << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}