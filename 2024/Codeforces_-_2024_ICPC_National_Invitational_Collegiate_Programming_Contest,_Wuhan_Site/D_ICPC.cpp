/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-26 19:08:08
 *
 * Problem: D. ICPC
 * Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
 * URL:     https://codeforces.com/gym/105143/problem/D
 * MemoryL: 1024 MB
 * TimeL:   6000 ms
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
    vector<vector<int>> dp(n + 1, vector<int> (n * 2 + 1));
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = a[i];
        if (i == 1) {
            for (int j = 1; j < n; j ++) dp[i][j] = dp[i][j - 1] + a[j + 1];
            for (int j = n; j <= n * 2; j ++) dp[i][j] = dp[i][j - 1];
            continue;
        } else if (i == n) {
            for (int j = 1; j < n; j ++) dp[i][j] = dp[i][j - 1] + a[n - j];
            for (int j = n; j <= n * 2; j ++) dp[i][j] = dp[i][j - 1];
            continue;
        }
        for (int j = 1; j < n + i - 1; j ++) {
            int sum = -1;
            int L = (i - 1) * 2, R = (n - i) * 2;
            if (L >= j) {
                if (i - j >= 1) sum = max(sum, s[i] - s[i - j - 1]);
                else sum = max(sum, s[i]);
            } else sum = max(sum, s[i + (j - L)]);
            if (R >= j) {
                if (i + j <= n) sum = max(sum, s[i + j] - s[i - 1]);
                else sum = max(sum, s[n] - s[i - 1]);
            } else sum = max(sum, s[n] - s[i - (j - R)]);
            dp[i][j] = sum;
        }
        for (int j = n + i - 1; j <= n * 2; j ++) dp[i][j] = dp[i][j - 1];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n * 2; j ++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i ++) {
        int res = 0;
        for (int j = 1; j <= n * 2; j ++) {
            res ^= j * dp[i][j];
        }
        ans ^= (i + res);
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