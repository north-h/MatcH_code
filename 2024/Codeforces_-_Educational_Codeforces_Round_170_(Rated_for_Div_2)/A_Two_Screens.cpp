/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-10-14 22:37:56
 *
 * Problem: A. Two Screens
 * Contest: Codeforces - Educational Codeforces Round 170 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/2025/problem/0
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    // debug2(a, b);
    int ans = 0;
    int n = max((int)a.size(), (int)b.size()) - 1;
    int m = min((int)a.size(), (int)b.size()) - 1;
    // debug1(n);
    int p = -1;
    for (int i = 0; i <= m; i ++) {
        // debug2(a[i], b[i]);
        if (a[i] != b[i]) break;
        p = i;
    }
    // debug1(p);
    if (p == -1) {
        cout << a.size() + b.size() << '\n';
        return ;
    }
    int sa = a.size() - 1, sb = b.size() - 1;
    cout << p + 2 + sa - p + sb - p << '\n';
    // string s, t;
    // cin >> s >> t;
    // int n = s.size();
    // int m = t.size();
    // // dp[i][j] 表示构建 s 的前 i 个字符和 t 的前 j 个字符所需的最少操作次数
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    // dp[0][0] = 0;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         if (dp[i][j] == INF) continue;
    //         // 1. 向屏幕1添加下一个字符
    //         if (i < n) {
    //             dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
    //         }
    //         // 2. 向屏幕2添加下一个字符
    //         if (j < m) {
    //             dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
    //         }
    //         // 3. 复制屏幕1到屏幕2
    //         if (i > 0 && i <= m) {
    //             string ss = s.substr(0, i);
    //             string tt = t.substr(0, i);
    //             if (ss == tt) {
    //                 dp[i][i] = min(dp[i][i], dp[i][j] + 1);
    //             }
    //         }
    //         // 4. 复制屏幕2到屏幕1
    //         if (j > 0 && j <= n) {
    //             string tt = t.substr(0, j);
    //             string ss = s.substr(0, j);
    //             if (tt == ss) {
    //                 dp[j][j] = min(dp[j][j], dp[i][j] + 1);
    //             }
    //         }
    //     }
    // }
    // cout << dp[n][m] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}