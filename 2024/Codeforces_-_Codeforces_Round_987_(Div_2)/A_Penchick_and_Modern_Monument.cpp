/*
 * ==================================================================================
 * Autaor:  norta_a
 * Time:    2024-11-15 20:35:29
 *
 * Problem: A. Pencaick and Modern Monument
 * Contest: Codeforces - Codeforces Round 987 (Div. 2)
 * URL:     attps://codeforces.com/contest/2031/problem/0
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);

    cout << n - ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}