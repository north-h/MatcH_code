/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-13 20:03:01 ms
 *
 * Problem: E - Count Arithmetic Subsequences
 * Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
 * URL:     https://atcoder.jp/contests/abc362/tasks/abc362_e
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 85;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

map<int, int> dp[N][N];

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j < i; j ++) {
            dp[i][2][a[i] - a[j]] ++;
        }
    }
    if (n == 1) cout << n << '\n';
    else cout << n << ' ' << n * (n - 1) / 2 << ' ';
    for (int len = 3; len <= n; len ++) {
        int ans = 0;
        for (int i = len; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                dp[i][len][a[i] - a[j]] += dp[j][len - 1][a[i] - a[j]];
                dp[i][len][a[i] - a[j]] %= mod;
                ans += dp[j][len - 1][a[i] - a[j]];
                ans %= mod;
            }
        }
        cout << ans << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}