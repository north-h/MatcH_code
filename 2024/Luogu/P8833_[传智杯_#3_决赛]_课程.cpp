/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:09 ms
 *
 * Problem: P8833 [传智杯 #3 决赛] 课程
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8833?contestId=166591
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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        mp[x] ++;
    }
    for (int i = 1, x; i <= m; i ++) {
        cin >> x;
        mp[x] ++;
    }
    int ans = 0;
    for (auto [x, y] : mp) ans += (y == 2);
    cout << ans << endl;
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