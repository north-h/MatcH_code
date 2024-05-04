/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-04 20:14:33 ms
 *
 * Problem: A - AtCoder Line
 * Contest: AtCoder - AtCoder Beginner Contest 352
 * URL:     https://atcoder.jp/contests/abc352/tasks/abc352_a
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if (x > y) swap(x, y);
    if (z >= x && z <= y) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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