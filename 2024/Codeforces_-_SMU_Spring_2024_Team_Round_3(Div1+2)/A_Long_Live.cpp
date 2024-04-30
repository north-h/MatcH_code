/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-30 13:02:36 ms
 *
 * Problem: A. Long Live
 * Contest: Codeforces - SMU Spring 2024 Team Round 3(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/521164/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    ll x, y; cin >> x >> y;
    ll gc = __gcd(x, y);
    ll lc = x * y / gc;
    cout << 1 << ' ' << lc / gc << '\n';
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