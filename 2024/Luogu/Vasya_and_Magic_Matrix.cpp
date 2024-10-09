/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 21:14:18
 *
 * Problem: Vasya and Magic Matrix
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/CF1042E
 * MemoryL: 250 MB
 * TimeL:   3000 ms
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
    vector g(n + 1, vector<int>(m + 1));
    map<int, vector<array<int, 2>>> mp;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            mp[g[i][j]].push_back({i, j});
        }
    }
    int x, y; cin >> x >> y;
    int ans = 0;
    
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}