/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 20:52:14
 *
 * Problem: FAVDICE - Favorite Dice
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/SP1026
 * MemoryL: 1 MB
 * TimeL:   391000 ms
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
    double ans = 0;
    vector<double> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i ++) {
        dp[i] = dp[i - 1] + n * 1.0 / (n - i + 1);
    }
    cout << fixed << setprecision(2) << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}