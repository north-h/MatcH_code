/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-11 20:11:37
 *
 * Problem: 最短？路径
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/91355/D
 * MemoryL: 524288 MB
 * TimeL:   4000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 300010, INF = 0x3f3f3f3f;

using namespace std;

vector<vector<int>> g;
int n, m, k;
int vis[N][10][2], val[N], dis[N][10][2];

void solve() {
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (int i = 1; i <= n; i ++) cin >> val[i];
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << 
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}