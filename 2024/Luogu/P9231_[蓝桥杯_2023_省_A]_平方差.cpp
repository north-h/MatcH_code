/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:29 ms
 *
 * Problem: P9231 [蓝桥杯 2023 省 A] 平方差
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9231?contestId=173756
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int l, r; cin >> l >> r;
    cout << (r + 1) / 2 + r / 4 - (l - 1 + 1) / 2 - (l - 1) / 4 << '\n';
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