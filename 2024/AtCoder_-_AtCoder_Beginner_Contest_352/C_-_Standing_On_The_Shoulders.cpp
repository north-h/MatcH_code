/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-04 20:14:45 ms
 *
 * Problem: C - Standing On The Shoulders
 * Contest: AtCoder - AtCoder Beginner Contest 352
 * URL:     https://atcoder.jp/contests/abc352/tasks/abc352_c
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
    int n; cin >> n;
    vector<array<int, 2>> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
        sum += a[i][0];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, sum - a[i][0] + a[i][1]);
    }
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