/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-18 22:36:19
 *
 * Problem: A. Diverse Game
 * Contest: Codeforces - Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1994/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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

int a[15][15], b[15][15];

void solve() {
    int n, m; cin >> n >> m;
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            mp[a[i][j]] = {i, j};
        }
    }
    if (n == 1 && m == 1) {
        cout << -1 << '\n';
        return ;
    }
    // for (auto [x, y] : mp) {
    //     cout << x << ':' << y.first << ' ' << y.second << '\n';
    // }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int x, y;
            // debug1(a[i][j]);
            if (a[i][j] == n * m) {
                x = mp[1].first, y = mp[1].second;
                b[i][j] = 1;
            } else {
                x = mp[a[i][j] + 1].first, y = mp[a[i][j] + 1].second;
                b[i][j] = a[i][j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}