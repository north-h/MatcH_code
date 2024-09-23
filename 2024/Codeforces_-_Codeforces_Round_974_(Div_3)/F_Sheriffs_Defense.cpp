/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-23 14:50:56
 *
 * Problem: F. Sheriff's Defense
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> val(n + 1);
    vector g(n + 1, vector<int>());
    for (int i = 1; i <= n; i ++) cin >> val[i];
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector dp(n + 1, vector<int>(2, 0));
    auto dfs = [&](auto dfs, int u, int f) -> void {
        dp[u][1] = val[u];
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += max(dp[v][0], dp[v][1] - c * 2);
        }
    };
    dfs(dfs, 1, 0);
    cout << max(dp[1][1], dp[1][0]) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}