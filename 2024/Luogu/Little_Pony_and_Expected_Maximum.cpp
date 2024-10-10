/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-10 18:52:58
 *
 * Problem: Little Pony and Expected Maximum
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/CF453A
 * MemoryL: 250 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> m >> n;
    double ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans += i * (pow(i * 1.0 / m, n) - pow((i - 1) * 1.0 / m, n));
    }
    cout << fixed << setprecision(4) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}