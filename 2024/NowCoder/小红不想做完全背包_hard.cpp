/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-07 23:54:04
 *
 * Problem: 小红不想做完全背包 （hard）
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78904/D
 * MemoryL: 524288 MB
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

using namespace std;  
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] %= k;
        if (a[i] == 0) a[i] = k;
    }
    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= k; j ++) {
            int x = (j + a[i]) % k;
            if (x == 0) x = k;
            dp[x] = min(dp[x], dp[j] + 1);
        }
    }
    cout << dp[k] << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}