/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-03 20:00:14 ms
 *
 * Problem: A - Leap Year
 * Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
 * URL:     https://atcoder.jp/contests/abc365/tasks/abc365_a
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 4) cout << 365 << '\n';
    else if (n % 4 == 0 && n % 4) cout << 366 << '\n';
    else if (n % 100 == 0 && n % 400) cout << 365 << '\n';
    else  cout << 366 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}