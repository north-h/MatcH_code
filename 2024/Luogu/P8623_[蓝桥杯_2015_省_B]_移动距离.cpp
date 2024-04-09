/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:18 ms
 *
 * Problem: P8623 [蓝桥杯 2015 省 B] 移动距离
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8623?contestId=166591
 * MemoryL: 128 MB
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
    int w, m, n;
    cin >> w >> m >> n;
    int hm = (m + w - 1) / w, lm = m % w;
    int hn = (n + w - 1) / w, ln = n % w;
    if (lm == 0) lm = w;
    if (ln == 0) ln = w;
    if (hm % 2 == 0) lm = (w - lm + 1);
    if (hn % 2 == 0) ln = (w - ln + 1);
    int ans = abs(hm - hn) + abs(lm - ln);
    cout << ans << '\n';
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