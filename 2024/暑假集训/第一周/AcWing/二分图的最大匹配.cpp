/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-13 16:06:08 ms
 *
 * Problem: 二分图的最大匹配
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/863/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<vector<int>> g(n1 + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> vis;
    vector<int> match(n2 + 1);
    auto dfs = [&](auto &&dfs, int  u) -> bool {
        for (auto v : g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            if (!match[v] || dfs(dfs, match[v])) {
                match[v] = u;
                return 1;
            }
        }
        return 0;
    };
    int ans = 0;
    for (int i = 1; i <= n1; i ++) {
        vector<int>(n1 + 1).swap(vis);
        if (dfs(dfs, i)) ans ++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}