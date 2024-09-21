/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-21 23:56:45
 *
 * Problem: E. Rendez-vous de Marian et Robin
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/E
 * MemoryL: 256 MB
 * TimeL:   5000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 200010, INF = 0x3f3f3f3f;

using namespace std;

vector<vector<array<int, 2>>> g;
int n, m, h;
set<int> H;
vector<array<int, 2>> ds, de;

vector<array<int, 2>> dij(int x) {
    vector<array<int, 2>> d(n + 1);
    for (int i = 1; i <= n; i ++) d[i][0] = d[i][1] = 1e15;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    d[x][0] = 0;
    if (H.count(x)) {
        d[x][1] = 0;
        pq.push({0, x, 1});
    } else pq.push({0, x, 0});
    map<int, map<int, int>> vis;
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t[1]][t[2]]) continue;
        vis[t[1]][t[2]] = 1;
        for (auto [x, y] : g[t[1]]) {
            if (t[2]) {
                if (d[x][1] > d[t[1]][1] + y / 2) {
                    d[x][1] = d[t[1]][1] + y / 2;
                    pq.push({d[x][1], x, t[2]});
                }
            } else {
                if (H.count(x)) {
                    if (d[x][1] > d[t[1]][0] + y) {
                        d[x][1] = d[t[1]][0] + y;
                        pq.push({d[x][1], x, 1});
                    }
                } else {
                    if (d[x][0] > d[t[1]][0] + y) {
                        d[x][0] = d[t[1]][0] + y;
                        pq.push({d[x][0], x, t[2]});
                    }
                }
            }
        }
    }
    return d;
}


void solve() {
    cin >> n >> m >> h;
    H.clear();
    ds.clear();
    de.clear();
    g.clear();
    g.resize(n + 1);
    for (int i = 1; i <= h; i ++) {
        int x; cin >> x;
        H.insert(x);
    }
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ds = dij(1);
    de = dij(n);
    int ans = 1e15;
    for (int i = 1; i <= n; i ++) {
        int dx = min(ds[i][0], ds[i][1]);
        int dy = min(de[i][0], de[i][1]);
        ans = min(ans, max(dx, dy));
    }
    if (ans == 1e15) ans = -1;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}