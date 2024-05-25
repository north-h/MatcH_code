/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-25 22:43:17
 *
 * Problem: D. Paint the Tree
 * Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1975/problem/D
 * MemoryL: 256 MB
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

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ':';
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    int cnt = 0, dis = 0;
    bool ok = false;
    int node = - 1;
    auto dfs = [&](auto dfs, int u, int f) -> void {
        // cnt ++;
        // if (cnt == n) ok = true;
        // if (ok) return ;
        // debug2(u, g[u].size());
        if (g[u].size() == 1 && g[u][0] == f) {
            node = u;
            return ;
        };
        for (auto v : g[u]) {
            if (v == f) continue;
            dis ++;
            dfs(dfs, v, u);
            dis ++;
        }
    };
    vector<int> depth(n + 1);
    auto dfs1 = [&](auto dfs1, int u, int f) -> void {
        for (auto v : g[u]) {
            if (v == f) continue;
            // debug2(u, v);
            depth[v] = depth[u] + 1;
            dfs1(dfs1, v, u);
        }
    };
    dfs(dfs, a, 0);
    dfs1(dfs1, a, 0);
    // for (int i = 1; i <= n; i ++) cout << depth[i] << ' '; cout << '\n';
    int x = 0, y = 0;
    if (depth[b] > 1) x = (depth[b] + 1) / 2;
    if (depth[node] > 1) y = depth[node];
    // debug2(dis, node);
    cout << dis - y + x << '\n';
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