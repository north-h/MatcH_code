/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:31 ms
 *
 * Problem: P8725 [蓝桥杯 2020 省 AB3] 画中漂流
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8725?contestId=166591
 * MemoryL: 128 MB
 * TimeL:   1000 ms
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
const int MOD = 1e9 + 7;


using namespace std;
using ll = long long;

int D, T, M;
int dp[3010][1510];

int dfs(int t, int m, int d) {
    if (dp[t][m] != -1) return dp[t][m];
    if (t == 0) {
        if (m != 0) return 0;
        return 1;
    }
    dp[t][m] = 0;
    if (m > 0) dp[t][m] = (dp[t][m] + dfs(t - 1, m - 1, d + 1)) % MOD;
    if (d > 1) dp[t][m] = (dp[t][m] + dfs(t - 1, m, d - 1)) % MOD;
    return dp[t][m];
}

void solve() {
    cin >> D >> T >> M;
    memset(dp, -1, sizeof dp);
    cout << dfs(T, M, D) << '\n';
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