/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-11 17:59:00 ms
 *
 * Problem: B. Grid with Arrows
 * Contest: Codeforces - The 2019 ICPC China Shaanxi Provincial Programming Contest
 * URL:     https://codeforces.com/gym/104460/problem/B
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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> val(n + 1, vector<int>(m + 1));
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> val[i][j];
        }
    }
    auto check = [&](int x, int y) -> bool {
        if (x >= 1 && y >= 1 && x <= n && y <= m) return true;
        return false;
    };
    vector<int> in(n * m + 1), out(n * m + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int x, y;
            // debug1((i - 1) * m + j);
            if (g[i][j] == 'r') {
                y = j + val[i][j];
                x = i;
                if (!check(x, y)) continue;
                out[(i - 1) * m + j] ++;
                in[(x - 1) * m + y] ++;
            } else if (g[i][j] == 'l') {
                y = j - val[i][j];
                x = i;
                if (!check(x, y)) continue;
                out[(i - 1) * m + j] ++;
                in[(x - 1) * m + y] ++;
            } else if (g[i][j] == 'u') {
                y = j;
                x = i - val[i][j];
                if (!check(x, y)) continue;
                out[(i - 1) * m + j] ++;
                in[(x - 1) * m + y] ++;
            } else {
                y = j;
                x = i + val[i][j];
                if (!check(x, y)) continue;
                out[(i - 1) * m + j] ++;
                in[(x - 1) * m + y] ++;
            }
            // debug1((x - 1) * m + y);
            // debug2(x, y);
        }
    }
    // for (int i = 1; i <= n * m; i ++) cout << in[i] << ' '; cout << '\n';
    // for (int i = 1; i <= n * m; i ++) cout << out[i] << ' '; cout << '\n';
    int f = 0;
    for (int i = 1; i <= n * m; i ++) {
        if (in[i] != out[i]) f ++;
    }
    if (f == 0 || f == 2 || f == 1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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