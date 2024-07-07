/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 20:00:25 ms
 *
 * Problem: C - Make Them Narrow
 * Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
 * URL:     https://atcoder.jp/contests/abc361/tasks/abc361_c
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    // for (int i = 1; i <= n; i ++) {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    int ans = INF;
    for (int i = 1, j = n - k; j <= n; j ++, i ++) {
        // debug1(a[j] - a[i]);
        ans = min(ans, a[j] - a[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}