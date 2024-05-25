/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:24 ms
 *
 * Problem: P8605 [蓝桥杯 2013 国 AC] 网络寻路
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8605?contestId=173756
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, m ; cin >> n >> m;
    vector<int> dg(n + 1);
    vector<array<int, 2>> b;
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        b.push_back({u, v});
        dg[v] ++;
        dg[u] ++;
    }
    ll ans = 0;
    for (int i = 0; i < m; i ++) {
        // debug1(dg[i]);
        ans += (ll)(dg[b[i][0]] - 1) * (dg[b[i][1]] - 1);
    }
    cout << ans * 2 << '\n';
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