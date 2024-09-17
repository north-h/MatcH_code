/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-17 15:48:06
 *
 * Problem: F. Mystery of Prime
 * Contest: Codeforces - SMU Autumn 2024 Team Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/550260/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 200010, INF = 0x3f3f3f3f;

using namespace std;

int vis[N];
vector<int> prime;

void euler(int n) {
    vis[1] = 1;
    for (int i = 2; i < n; i ++) {
        if (!vis[i]) prime.push_back(i);
        for (auto j : prime) {
            if (j * i >= n) break;
            vis[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

void solve() {
    euler(N);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(4, INF));
    dp[1][0] = 0, dp[1][1] = dp[1][2] = dp[1][3] = 1;
    for (int i = 2; i <= n; i ++) {
        if (!vis[a[i] + a[i - 1]]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (!vis[a[i] + 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (a[i] & 1) dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        else dp[i][0] = min(dp[i][0], dp[i - 1][3]);

        if (!vis[a[i - 1] + 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);

        if (a[i - 1] % 2) dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);

        if (a[i - 1] % 2 == 0) dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
        dp[i][3] = min(dp[i][3], dp[i - 1][2] + 1);
    }
    cout << ranges::min(dp[n]) << '\n';
    // cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}