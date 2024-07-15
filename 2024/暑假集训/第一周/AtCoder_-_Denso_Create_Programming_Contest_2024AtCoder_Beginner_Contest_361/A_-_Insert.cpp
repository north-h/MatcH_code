/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 20:00:12 ms
 *
 * Problem: A - Insert
 * Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
 * URL:     https://atcoder.jp/contests/abc361/tasks/abc361_a
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
    int n, k, x; cin >> n >> k >> x;
    for (int i = 1, y; i <= n; i ++) {
        cin >> y;
        cout << y << ' ';
        if (i == k) cout << x << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}