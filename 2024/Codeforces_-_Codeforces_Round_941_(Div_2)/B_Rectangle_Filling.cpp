/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-28 08:48:57
 *
 * Problem: B. Rectangle Filling
 * Contest: Codeforces - Codeforces Round 941 (Div. 2)
 * URL:     https://codeforces.com/contest/1966/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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

char g[510][510];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= m; i ++) {
        if (g[1][1] == g[n][i] && (g[n][m] == g[1][1] || g[1][m] == g[1][1])) {
            cout << "YES" << '\n';
            return ;
        }
    }
    for (int i = 1; i <= m; i ++) {
        if (g[n][1] == g[1][i] && (g[n][m] == g[n][1] || g[1][m] == g[n][1])) {
            cout << "YES" << '\n';
            return ;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (g[1][1] == g[i][m] && (g[n][1] == g[1][1] || g[n][m] == g[1][1])) {
            cout << "YES" << '\n';
            return ;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (g[1][m] == g[i][1] && (g[n][1] == g[1][m] || g[n][m] == g[1][m])) {
            cout << "YES" << '\n';
            return ;
        }
    }
    cout << "NO" << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}