/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 13:20:51 ms
 *
 * Problem: G2. Permutation Problem (Hard Version)
 * Contest: Codeforces - Codeforces Round 954 (Div. 3)
 * URL:     https://codeforces.com/contest/1986/problem/G2
 * MemoryL: 128 MB
 * TimeL:   3000 ms
 * ==============================================================
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
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int ans = INF;
    for (int i = 1; i <= 10; i ++) ans = min(ans, abs(i - x1) + abs(x2 - i) + abs(x3 - i));
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