/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-10 21:07:19
 *
 * Problem: P1850 [NOIP2016 提高组] 换教室
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1850
 * MemoryL: 500 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, v, e; cin >> n >> m >> v >> e;
    vector<int> c(n + 1), d(n + 1);
    vector<double> k(n + 1);
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i <= n; i ++) cin >> d[i];
    for (int i = 1; i <= n; i ++) cin >> k[i];
    vector f(v + 1, vector<double>(v + 1, INF));
    for (int i = 1; i <= v; i ++) f[i][i] = 0;
    for (int i = 1; i <= e; i ++) {
        int u, v, w; cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w * 1.0);
    }
    for (int k = 1; k <= v; k ++) {
        for (int i = 1; i <= v; i ++) {
            for (int j = 1; j <= v; j ++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    vector dp(n + 1, vector<vector<double>>(m + 2, vector<double>(2, INF)));
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j <= min(i, m); j ++) {
            dp[i][j][0] = min(dp[i - 1][j][0] + f[c[i - 1]][c[i]],
                              dp[i - 1][j][1]
                              + f[d[i - 1]][c[i]] * k[i - 1]
                              + f[c[i - 1]][c[i]] * (1 - k[i - 1]));
            if (j) {
                dp[i][j][1] = min(dp[i][j][ 1], dp[i - 1][j - 1][0]
                                  + f[c[i - 1]][d[i]] * k[i]
                                  + f[c[i - 1]][c[i]] * (1 - k[i]));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1]
                                  + f[c[i - 1]][c[i]] * (1 - k[i]) * (1 - k[i - 1])
                                  + f[c[i - 1]][d[i]] * (1 - k[i - 1]) * k[i]
                                  + f[d[i - 1]][c[i]] * k[i - 1] * (1 - k[i])
                                  + f[d[i - 1]][d[i]] * k[i - 1] * k[i]);
            }
        }
    }
    double ans = INF;
    for (int i = 0; i <= m; i ++) ans = min(min(dp[n][i][0], dp[n][i][1]), ans);
    cout << fixed << setprecision(2) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}