/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-12 19:18:14
 *
 * Problem: B. New Year and Domino
 * Contest: Codeforces - SMU Autumn 2024 Trial 3
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549249/problem/B
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

char a[510][510];
int s[510][510];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == '.' && a[i][j + 1] == '.') s[i][j] ++;
            if (a[i][j] == '.' && a[i + 1][j] == '.') s[i][j] ++;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int q; cin >> q;
    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        for (int i = x1; i <= x2; i ++) if (a[i][y2] == '.' && a[i][y2 + 1] == '.') ans --;
        for (int i = y1; i <= y2; i ++) if (a[x2][i] == '.' && a[x2 + 1][i] == '.') ans --;
        cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}