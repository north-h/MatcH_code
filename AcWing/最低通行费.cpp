/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-28 00:10:57
 *
 * Problem: 最低通行费
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/description/1020/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */
#include<bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    dp[0][1] = dp[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}