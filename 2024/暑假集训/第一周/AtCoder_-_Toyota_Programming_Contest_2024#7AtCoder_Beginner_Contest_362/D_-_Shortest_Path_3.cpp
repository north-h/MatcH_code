/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-13 20:02:56 ms
 *
 * Problem: D - Shortest Path 3
 * Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
 * URL:     https://atcoder.jp/contests/abc362/tasks/abc362_d
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
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

int n, m;
vector<int> val, dis;
vector<vector<array<int, 2>>> g;

void dijkstra(int x) {
    vector<int> vis(n + 1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
    q.push({0, x});
    dis[x] = 0;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        if (vis[t[1]]) continue;
        vis[t[1]] = 1;
        for (auto [x, y] : g[t[1]]) {
            if (dis[x] > dis[t[1]] + y) {
                dis[x] = dis[t[1]] + y;
                q.push({dis[x], x});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    val.resize(n + 1);
    g.resize(n + 1);
    dis.resize(n + 1, 1e15);
    for (int i = 1; i <= n; i ++) cin >> val[i];
    for (int i = 1; i <= m; i ++) {
        int u, v, b; cin >> u >> v >> b;
        g[u].push_back({v, b + val[v]});
        g[v].push_back({u, b + val[u]});
    }
    dijkstra(1);
    for (int i = 2; i <= n; i ++) {
        cout << dis[i] + val[1] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}