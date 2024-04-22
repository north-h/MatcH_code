/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-20 20:26:58 ms
 *
 * Problem: A - Past ABCs
 * Contest: AtCoder - AtCoder Beginner Contest 350
 * URL:     https://atcoder.jp/contests/abc350/tasks/abc350_a
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
    string s;
    cin >> s;
    int x = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
    // debug1(x);
    if (x != 316 && x > 0 && x <= 349 && s.substr(0, 3) == "ABC") cout << "Yes" << endl;
    else cout << "No" << '\n';
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