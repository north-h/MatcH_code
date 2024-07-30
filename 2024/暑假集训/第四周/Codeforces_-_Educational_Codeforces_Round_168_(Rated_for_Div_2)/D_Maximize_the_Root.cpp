/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-30 22:37:40
 *
 * Problem: D. Maximize the Root
 * Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1997/problem/D
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
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

void solve() {
    int n; cin >> n;
    vector<int> val(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i ++) cin >> val[i];
    for (int i = 2; i <= n; i ++) {
        int x; cin >> x;
        g[x].push_back(i);
        // g[i].push_back(x);
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ':';
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    int cnt = 1;
    auto dfs = [&](auto && dfs, int u, int f) -> int {
        if (g[u].size() == 0) return val[u];
        int mn = INF;
        for (auto v : g[u]) {
            if (v == f) continue;
            mn = min(mn, dfs(dfs, v, u));
        }
        // debug2(u, mn);
        if (mn >= 1) {
            if (cnt > mn) cnt = 1;
            val[u] += cnt ++;
        }
        return val[u];
    };
    dfs(dfs, 1, 0);
    cout << val[1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}