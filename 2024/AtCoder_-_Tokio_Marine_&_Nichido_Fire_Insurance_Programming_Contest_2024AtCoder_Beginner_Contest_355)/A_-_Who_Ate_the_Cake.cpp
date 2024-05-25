/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 20:00:13 ms
 *
 * Problem: A - Who Ate the Cake?
 * Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
 * URL:     https://atcoder.jp/contests/abc355/tasks/abc355_a
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
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b) cout << -1 << '\n';
    else {
        if (a == 1 && b == 2) cout << 3 << '\n';
        else if (a == 2 && b == 3) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
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