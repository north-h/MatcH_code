/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:35 ms
 *
 * Problem: P8730 [蓝桥杯 2020 国 ABC] 皮亚诺曲线距离
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8730?contestId=166591
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
    vector<array<int, 2>> a = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 1}, {1, 0}, {2, 0}, {2, 1}, {2, 2}};
    int k;
    cin >> k;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int fs, fe;
    for (int i = 0; i < a.size(); i ++) {
        if (sx == a[i][0] && sy == a[i][1]) fs = i;
        if (ex == a[i][0] && ey == a[i][1]) fe = i;
    }
    cout << fe - fs << '\n';
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