/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-03 20:00:28 ms
 *
 * Problem: D - AtCoder Janken 3
 * Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
 * URL:     https://atcoder.jp/contests/abc365/tasks/abc365_d
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<array<int, 3>> dp(n + 2);
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == 'R') {
            dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        } else if (s[i] == 'P') {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        }
    }
    if (s.back() == 'R') cout << max(dp[n][0], dp[n][1]);
    else if (s.back() == 'P') cout << max(dp[n][1], dp[n][2]);
    else cout << max(dp[n][0], dp[n][2]);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}