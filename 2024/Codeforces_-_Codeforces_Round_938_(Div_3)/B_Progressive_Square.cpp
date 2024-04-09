/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-08 23:53:50
 *
 * Problem: B. Progressive Square
 * Contest: Codeforces - Codeforces Round 938 (Div. 3)
 * URL:     https://codeforces.com/contest/1955/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> b(n * n + 1);
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n * n; i ++) cin >> b[i];
    sort(b.begin() + 1, b.end());
    int p = 1;
    if (c < d) {
        for (int i = 1; i <= n; i ++) {
            int x = i, y = 1;
            while (x >= 1 && y <= n) {
                g[x --][y ++] = b[p ++];
            }
        }
        for (int i = 2; i <= n; i ++) {
            int x = n, y = i;
            while (x >= 1 && y <= n) {
                g[x --][y ++] = b[p ++];
            }
        }
    } else {
        for (int i = 1; i <= n; i ++) {
            int x = 1, y = i;
            while (x <= n && y >= 1) {
                g[x ++][y --] = b[p ++];
            }
        }
        for (int i = 2; i <= n; i ++) {
            int x = i, y = n;
            while (x <= n && y >= 1) {
                g[x ++][y --] = b[p ++];
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 2; j <= n; j ++) {
            if (g[i][j] - g[i][j - 1] != d) {
                cout << "NO" << '\n';
                return ;
            }
        }
    }
    for (int j = 1; j <= n; j ++) {
        for (int i = 2; i <= n; i ++) {
            if (g[i][j] - g[i - 1][j] != c) {
                cout << "NO" << '\n';
                return ;
            }
        }
    }
    cout << "YES" << '\n';
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