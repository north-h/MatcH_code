/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-30 22:48:30
 *
 * Problem: D1. Reverse Card (Easy Version)
 * Contest: Codeforces - Codeforces Round 942 (Div. 2)
 * URL:     https://codeforces.com/contest/1972/problem/D1
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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; i ++) {
        ll x = max((ll)i * (i - 1), 1ll);
        ans += (n - x + 1 + (ll)i * i - 1) / ((ll)i * i);
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