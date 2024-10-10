/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 22:07:46
 *
 * Problem: P3802 小魔女帕琪
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3802
 * MemoryL: 125 MB
 * TimeL:   1000 ms
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
    // int n, m; cin >> m >> n;
    // vector<double> dp(n + 1);
    // dp[1] = n * (n + 1) / n * 2;
    // for (int i = 2; i <= n; i ++) {
    //     dp[i] = dp[i - 1] * i;
    // }
    // cout << fixed << setprecision(10) << dp[n] << '\n';
    for (int i = 1; i <= 6; i ++) {
        for (int j = 1; j <= 6; j ++) {
            for (int k = 1; k <= 6; k ++) {
                cout << i << ' ' << j << ' ' << k << ':' << max({i, j, k}) << '\n';
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