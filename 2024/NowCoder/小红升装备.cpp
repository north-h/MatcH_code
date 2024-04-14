/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-14 19:25:28
 *
 * Problem: 小红升装备
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/80259/D
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==================================================================================
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

int dp[310][310];

void solve() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 5>> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = 0;
        for (int j = 1; j <= x; j ++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= a[i][4] && k * a[i][2] + a[i][1] <= j; k ++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * a[i][2] - a[i][1]] + k * a[i][3] + a[i][0]);
            }
        }
    }
    cout << dp[n][x] << '\n';
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