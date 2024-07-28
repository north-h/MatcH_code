/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-27 15:45:07 ms
 *
 * Problem: 巡逻
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/description/352/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int depth = 0;
    auto dfs = [&](auto &dfs, int u, int f, int d) -> void {
        depth = max(depth, d);
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u, d + 1);
        }
    };
    dfs(dfs, 1, 0, 0);
    int ans = 0;
    if (k == 1) ans = (n - 1) * 2 - depth;
    else ans = (n - 1) * 2 - depth - 1;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}