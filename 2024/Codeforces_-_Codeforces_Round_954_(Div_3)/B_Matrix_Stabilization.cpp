/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 13:14:11 ms
 *
 * Problem: B. Matrix Stabilization
 * Contest: Codeforces - Codeforces Round 954 (Div. 3)
 * URL:     https://codeforces.com/contest/1986/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 2, vector<int> (m + 2, -1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    // while (true) {
    int f = false, vx = -1, vy = -1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            bool ff = true;
            for (int k = 0; k < 4; k ++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > m) continue;
                if (g[x][y] >= g[i][j]) ff = false;
            }
            if (ff) {
                g[i][j] = max({g[i - 1][j], g[i + 1][j], g[i][j - 1], g[i][j + 1]});
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
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