/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-17 20:07:10
 *
 * Problem: 比特跳跃
 * Contest: Virtual Judge - HDU
 * URL:     https://vjudge.net/problem/HDU-7464
 * MemoryL: 256 MB
 * TimeL:   6000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

vector<vector<array<int, 2>>> g;
int n, m, k;
vector<int> d;

void dijkstra() {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    vector<int> vis(n + 1);
    pq.push({0, 1});
    d[1] = 0;
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t[1]]) continue;
        for (auto [x, y] : g[t[1]]) {
            if (d[t[1]] + y < d[x]) {
                d[x] = d[t[1]] + y;
                pq.push({d[x], x});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    g.resize(n + 1);
    d.resize(n + 1, 1e17);
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 2; i <= n; i ++) {
        g[1].push_back({i, (1 | i) * k});
        g[i].push_back({1, (1 | i) * k});
    }
    dijkstra();
    auto nd = d;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; (1 << j) <= n; j ++) {
            if (i >> j & 1) nd[i] = min(nd[i], nd[i ^ (1 << j)]);
        }
        d[i] = min(d[i], nd[i] + k * i);
    }
    for (int i = n; i >= 2; i --) {
        for (int j = i; j ; j = (j - 1) & i) {
            d[i] = min(d[i], d[j] + k * i);
        }
    }
    dijkstra();
    for (int i = 2; i <= n; i ++) cout << d[i] << ' ';
    cout << '\n';
    g.clear();
    d.clear();
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}