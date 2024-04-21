/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-21 22:41:05
 *
 * Problem: A. Stickogon
 * Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
 * URL:     https://codeforces.com/contest/1957/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        mp[x] ++;
    }
    int ans = 0;
    for (auto [x, y] : mp) ans += y / 3;
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