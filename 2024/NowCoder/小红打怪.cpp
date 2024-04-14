/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-14 19:01:23
 *
 * Problem: 小红打怪
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/80259/B
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

int n, m;
char g[N][N];
int a[N][N], h[N][N], l[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == '*') a[i][j] = 1;
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            h[i][j] = h[i][j - 1] + a[i][j];
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << h[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            l[j][i] = l[j - 1][i] + a[j][i];
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << l[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i][j] == 'A') ans += h[i][j];
            else if (g[i][j] == 'D') ans += (h[i][m] - h[i][j - 1]);
            else if (g[i][j] == 'W') ans += l[i][j];
            else if (g[i][j] == 'S')ans += (l[n][j] - l[i - 1][j]);
        }
    }
    cout << ans << '\n';
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