/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 20:00:21 ms
 *
 * Problem: B - Intesection of Cuboids
 * Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
 * URL:     https://atcoder.jp/contests/abc361/tasks/abc361_b
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
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
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    if (g >= d || h >= e || i >= f ||
            j <= a ||  k <= b || l <= c) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}