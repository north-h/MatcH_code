/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-11 20:00:12 ms
 *
 * Problem: A - Buildings
 * Contest: AtCoder - AtCoder Beginner Contest 353
 * URL:     https://atcoder.jp/contests/abc353/tasks/abc353_a
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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 2; i <= n; i ++) {
        if (a[i] > a[1]) {
            cout << i << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
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