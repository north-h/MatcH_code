/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-21 22:41:17
 *
 * Problem: D. A BIT of an Inequality
 * Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
 * URL:     https://codeforces.com/contest/1957/problem/D
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

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<ll>> cnt(n + 1, vector<ll>(30));
    int s = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> a[i]; s ^= a[i];
        for (int j = 0; j < 30; j ++) {
            cnt[i][j] = cnt[i - 1][j] + (s >> j & 1);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        int k = 29;
        while (k >= 0 && (a[i] >> k & 1) == 0) k --;
        if (k == -1) continue;
        ans += (cnt[n][k] - cnt[i - 1][k]) * cnt[i - 1][k];
        ans += (n - i + 1 - (cnt[n][k] - cnt[i - 1][k])) * (i - cnt[i - 1][k]);
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
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}