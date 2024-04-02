/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-19 00:45:42
 *
 * Problem: P1879 [USACO06NOV] Corn Fields G
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1879
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;
const int mod = 1e8;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            sum[i] = (sum[i] << 1) + a[i][j];
        }
    }
    vector<int> p((1<<m) + 1);
    for (int i = 0; i < 1<<m; i ++) {
        int x = (i & (i << 1));
        int y = (i & (i >> 1));
        if (x == 0 && y == 0) p[i] = 1;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(1<<m + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 1<<m; j ++) {
            if (!p[j]) continue;
            if ((j & sum[i]) != j) continue;
            for (int k = 0; k < 1<<m; k ++) {
                if ((k & j)) continue;
                dp[i][j] = dp[i][j] + dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 1<<m; i ++) {
        ans = (ans + dp[n][i]) % mod;
    }
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