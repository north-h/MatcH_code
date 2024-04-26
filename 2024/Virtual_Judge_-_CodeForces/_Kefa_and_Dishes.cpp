/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-25 20:03:48 ms
 *
 * Problem:  Kefa and Dishes
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-580D#author=GPT_zh
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * =========================================================
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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<vector<ll>> dp(1 << n + 1, vector<ll>(n + 1));
    map<int, map<int, int>> mp;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) {
        int x, y, z; cin >> x >> y >> z;
        mp[x][y] = z;
    }
    for (int i = 0; i < n; i ++) dp[1 << i][i + 1] = a[i + 1];
    for (int op = 0; op < 1 << n; op ++) {
        for (int i = 0; i < n; i ++) {
            if (!(op >> i & 1)) continue;
            for (int j = 0; j < n; j ++) {
                if (op >> j & 1) continue;
                int p = op | (1 << j);
                dp[p][j + 1] = max(dp[op][i + 1] + mp[i + 1][j + 1] + a[j + 1], dp[p][j + 1]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 1 << n; i ++) {
        if (__builtin_popcount(i) != m) continue;
        for (int j = 1; j <= n; j ++) {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << '\n';
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