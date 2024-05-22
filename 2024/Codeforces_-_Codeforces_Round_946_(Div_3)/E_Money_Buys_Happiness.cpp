/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:46
 *
 * Problem: E. Money Buys Happiness
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/E
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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

using namespace std;
using ll = long long;

void solve() {
    int m, x; cin >> m >> x;
    vector<int> c(m + 1), h(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> c[i] >> h[i];
    }
    int sum = accumulate(h.begin() + 1, h.end(), 0);
    vector<ll> dp(sum + 1, 1e10);
    dp[0] = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = sum; j >= h[i]; j --) {
            if (dp[j - h[i]] + c[i] <= (ll)(i - 1) * x) {
                dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
            }
        }
    }
    for (int i = sum ; i >= 0; i --) {
        if (dp[i] != 1e10) {
            cout << i << '\n';
            return ;
        }
    }
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