/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 20:28:51
 *
 * Problem: 小红的树上路径查询（easy）
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/92662/F
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
// #define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, qq; cin >> n >> qq;
    vector g(n + 1, vector<int>());
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x, y; cin >> x >> y;
    vector<int> edge, vi(n + 1);
    bool ok = false;
    auto dfs = [&](auto dfs, int u, int f)-> void {
        // debug2(u, y);
        // for (auto i : edge) cout << i << ' ';
        // cout << '\n';
        if (u == y) ok = true;
        if (ok) return ;
        for (auto v : g[u]) {
            if (v == f) continue;
            edge.push_back(v);
            dfs(dfs, v, u);
            if (!ok) edge.pop_back();
            if (ok) return ;
        }
    };
    edge.push_back(x);
    dfs(dfs, x, -1);
    // edge.push_back(y);
    // for (auto i : edge) cout << i << ' ';
    // cout << '\n';
    queue<int> q;
    vector<int> d(n + 1), vis(n + 1);
    for (auto i : edge) q.push(i), d[i] = 0, vis[i] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (vis[i]) continue;
            d[i] = d[t] + 1;
            q.push(i);
            vis[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans += d[i];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}