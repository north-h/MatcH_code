/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:20 ms
 *
 * Problem: P8828 [传智杯 #3 练习赛] 直角三角形
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8828?contestId=173756
 * MemoryL: 128 MB
 * TimeL:   1000 ms
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
    ll c; cin >> c;
    for (int a = 1; a <= c; a ++) {
        ll x = c * c - a * a;
        if ((int)sqrt(x) * (int)sqrt(x) == x) {
            // debug2(x, sqrt(x) * sqrt(x));
            cout << a << ' ' << sqrt(x) << '\n';
            return ;
        }
    }
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