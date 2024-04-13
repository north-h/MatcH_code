/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:48 ms
 *
 * Problem: P8724 [蓝桥杯 2020 省 AB3] 限高杆
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8724?contestId=166591
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

int n, m;
vector<array<int, 3>> g[N];


int dijkstra(bool f) {
    vector<int> dis(n + 1, INF), vis(n + 1);
    dis[1] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (vis[t[1]])continue;
        vis[t[1]] = true;
        for (auto [x, y, z] : g[t[1]]) {
            if (f && z) continue;
            if (dis[x] > dis[t[1]] + y) {
                dis[x] = dis[t[1]] + y;
                heap.push({dis[x], x});
            }
        }
    }
    if (dis[n] == INF) return -1;
    return dis[n];
}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }
    bool ok = true;
    int d1 = dijkstra(ok);
    ok = false;
    int d2 = dijkstra(ok);
    cout << d1 - d2 << '\n';
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