/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-31 21:12:39
 *
 * Problem: P5960 【模板】差分约束
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P5960
 * MemoryL: 128 MB
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
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i ++) g[0].push_back({i, 0});
    // for (int i = 0; i <= n; i ++) {
    //     cout << i << ":\n";
    //     for (auto [j, k] : g[i]) cout << j << ' ' << k << '\n';
    //     cout << '\n';
    // }
    vector<int> dis(n + 1, INF), vis(n + 1), cnt(n + 1);
    queue<int> q;
    dis[0] = 0;
    vis[0] = 1;
    q.push(0);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        vis[t] = 0;
        for (auto [x, y] : g[t]) {
            if (dis[x] > dis[t] + y) {
                dis[x] = dis[t] + y;
                cnt[x] ++;
                if (cnt[x] >= n + 1) {
                    cout << "NO\n";
                    return ;
                }
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
    }
    // cout << "YES\n";
    for (int i = 1; i <= n; i ++) cout << dis[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}