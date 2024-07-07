/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-07 14:25:52 ms
 *
 * Problem: D. Manhattan Circle
 * Contest: Codeforces - Codeforces Round 952 (Div. 4)
 * URL:     https://codeforces.com/contest/1985/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
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
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    vector<vector<int>> lie(n + 1, vector<int> (m + 1));
    vector<vector<int>> hang(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                lie[i][j] = hang[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            hang[i][j] += hang[i][j - 1];
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << hang[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int j = 1; j <= m; j ++) {
        for (int i = 1; i <= n; i ++) {
            lie[i][j] += lie[i - 1][j];
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << lie[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    auto check = [&](int x, int y) -> bool {
        int v1 = hang[x][y];
        int v2 = hang[x][m] - hang[x][y - 1];
        int v3 = lie[x][y];
        int v4 = lie[n][y] - lie[x - 1][y];
        return v1 == v2 && v2 == v3 && v3 == v4;
    };
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i][j] == '#' && check(i, j)) {
                cout << i << ' ' << j << '\n';
                return ;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}