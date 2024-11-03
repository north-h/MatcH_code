/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-11-02 12:43:31
 *
 * Problem: J. Takeout Delivering
 * Contest: Codeforces - SMU Autumn 2024 Team Round 11
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/563273/problem/J
 * MemoryL: 128 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

vector<vector<pair<int, int>>> g;
int n, m;

vector<int> dij(int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> vis(n + 1), d(n + 1, INF);
    pq.push({0, x});
    d[x] = 0;
    while (pq.size()) {
        auto [t0, t1] = pq.top();
        pq.pop();
        if (vis[t1]) continue;
        vis[t1] = 1;
        for (auto [x, y] : g[t1]) {
            if (d[x] >= max(y, t0)) {
                d[x] = max(y, t0);
                pq.push({d[x], x});
            }
        }
    }
    return d;
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    vector<array<int, 3>> B;
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        B.push_back({u, v, w});
    }
    auto st = dij(1), ed = dij(n);
    int ans = LLONG_MAX;
    for (auto [u, v, w] : B) {
        if (max(st[u], ed[v]) <= w) ans = min(ans, w + max(st[u], ed[v]));
        if (max(st[v], ed[u]) <= w) ans = min(ans, w + max(st[v], ed[u]));
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