/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 13:59:15
 *
 * Problem: 矩阵的拆解之谜
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/93674/B
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
        }
    }
    auto ans = g;
    for (int i = 1; i <= n; i ++) ans[i][i] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) continue;
            if ((g[i][j] - g[j][i]) % 2 == 0) {
                ans[i][j] = -(g[j][i] - g[i][j]) / 2;
                ans[j][i] = ans[j][i];
            } else if ((g[j][i] - g[i][j]) % 2 == 0) {
                ans[j][i] = -(g[i][j] - g[j][i]) / 2;
                ans[i][j] = ans[j][i];
            } else {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << g[i][j] - ans[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}