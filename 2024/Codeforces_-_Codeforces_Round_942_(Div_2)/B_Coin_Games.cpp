/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-30 22:48:21
 *
 * Problem: B. Coin Games
 * Contest: Codeforces - Codeforces Round 942 (Div. 2)
 * URL:     https://codeforces.com/contest/1972/problem/B
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
    int n; cin >> n;
    string s; cin >> s;
    // if (n == 1) {
    //     if (s == "D") cout << "NO" << '\n';
    //     else cout << "YES" << '\n';
    //     return ;
    // }
    // if (n == 2) {
    //     if (s == "UU" || s == "DD") cout << "NO" << '\n';
    //     else cout << "YES" << '\n';
    //     return ;
    // }
    int u = 0, d = 0;
    for (auto i : s) {
        u += i == 'U';
        d += i == 'D';
    }
    if (u & 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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