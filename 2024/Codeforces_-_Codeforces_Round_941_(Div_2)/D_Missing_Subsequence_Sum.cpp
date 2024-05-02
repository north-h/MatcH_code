/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-28 08:49:06
 *
 * Problem: D. Missing Subsequence Sum
 * Contest: Codeforces - Codeforces Round 941 (Div. 2)
 * URL:     https://codeforces.com/contest/1966/problem/D
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
    int n, k; cin >> n >> k;
    int h = log2(k);
    cout << 23 << '\n';
    for (int i = 0; i <= 20; i ++) {
        if (i == h) continue;
        cout << (1 << i ) << ' ';
    }
    // debug1(h);
    cout << k - (1 << h) << ' ' << k + 1 << ' ' << k + 1 + (1 << h) << '\n';
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