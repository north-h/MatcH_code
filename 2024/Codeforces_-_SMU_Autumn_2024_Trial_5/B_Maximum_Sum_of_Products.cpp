/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-14 14:39:10
 *
 * Problem: B. Maximum Sum of Products
 * Contest: Codeforces - SMU Autumn 2024 Trial 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549677/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    vector dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i] * b[i], dp[i][i] = a[i] * b[i];
    int ans = s[n];
    for (int len = 2; len <= n; len ++) {
        for (int i = 1; i + len - 1 <= n; i ++) {
            int l = i, r = i + len - 1;
            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r] + a[r] * b[l];
            ans = max(ans, dp[l][r] + s[l - 1] + s[n] - s[r]);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}