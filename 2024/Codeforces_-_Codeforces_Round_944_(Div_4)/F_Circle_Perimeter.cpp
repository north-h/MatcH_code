/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-11 13:31:48
 *
 * Problem: F. Circle Perimeter
 * Contest: Codeforces - Codeforces Round 944 (Div. 4)
 * URL:     https://codeforces.com/contest/1971/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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
    int n; cin >> n;
    auto check = [&] (int x, int y) -> bool {
        int v = x * x + y * y;
        int c1 = n * n, c2 = (n + 1) * (n + 1);
        if (v >= c1 && v < c2) return true;
        return false;
    };
    ll ans = 0;
    for (int i = 1, j = n; i <= n && i < j; i ++) {
        if (check(i, j))  {
            if (i != j) ans ++;
            if (check(i, j - 1) && i != j - 1) ans ++;
        } else j --, i --;
    }
    ans *= 2;
    double t = floor((n + 1) * 1.0 / sqrt(2)) * sqrt(2);
    if (t >= n && t < n + 1) ans ++;
    cout << ans * 4 + 4 << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}