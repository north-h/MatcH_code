/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-21 22:41:13
 *
 * Problem: C. How Does the Rook Move?
 * Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
 * URL:     https://codeforces.com/contest/1957/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int m = n;
    for (int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        if (x == y) m --;
        else m -= 2;
    }
    if (m <= 1) {
        cout << 1 << '\n';
        return ;
    }
    vector<ll> dp(m + 1);
    dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= m; i ++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 % mod * (i - 1) % mod) % mod;
    }
    cout << dp[m] << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}