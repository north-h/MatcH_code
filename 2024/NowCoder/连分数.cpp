/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-11 19:02:20
 *
 * Problem: 连分数
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/91355/B
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
// #define double long double
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

double calc(double x, int n) {
    if (n == 1) return 1;
    return (x + 1.0 / calc(x, n - 1));
}

map<double, double> mp;

void solve() {
    double a; cin >> a;
    double ans = calc(a, 500);
    if (a < 1) ans = mp[a];
    cout << fixed << setprecision(15) << ans << '\n';
    // for (auto [x, y] : mp) cout << x << ' ' << y << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 1; i <= 100; i ++) mp[i * 1.0 / 100] = calc(i * 1.0 / 100, 2000);
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}