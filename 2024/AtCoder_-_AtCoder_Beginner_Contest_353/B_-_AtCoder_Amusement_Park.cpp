/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-11 20:00:17 ms
 *
 * Problem: B - AtCoder Amusement Park
 * Contest: AtCoder - AtCoder Beginner Contest 353
 * URL:     https://atcoder.jp/contests/abc353/tasks/abc353_b
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
    int n, k; cin >> n >> k;
    int ans = 0, c = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (c + x <= k) c += x;
        else {
            ans ++;
            c = x;
        }
    }
    cout << ans + 1 << '\n';
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