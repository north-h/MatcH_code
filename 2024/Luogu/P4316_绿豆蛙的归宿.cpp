/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 21:32:17
 *
 * Problem: P4316 绿豆蛙的归宿
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P4316
 * MemoryL: 125 MB
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
    int n, m; cin >> n >> m;
    vector g(n + 1, vector<array<int, 2>>());
    vector<int> in(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    double ans = 0;
    auto dfs = [&](auto dfs, double gl, int len, int u) -> void {
        if (u == n) {
            ans += gl * len;
            return ;
        }
        int k = (int)g[u].size();
        // debug2(u, k);
        for (auto [v, w] : g[u]) {
            dfs(dfs, gl * (1.0 / k), len + w, v);
        }
    };
    dfs(dfs, 1, 0, 1);
    cout << fixed << setprecision(2) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}