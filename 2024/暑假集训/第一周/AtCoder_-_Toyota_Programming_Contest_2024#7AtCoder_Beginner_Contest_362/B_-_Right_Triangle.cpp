/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-13 20:02:48 ms
 *
 * Problem: B - Right Triangle
 * Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
 * URL:     https://atcoder.jp/contests/abc362/tasks/abc362_b
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int check(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int a = check(xa, ya, xb, yb);
    int b = check(xa, ya, xc, yc);
    int c = check(xc, yc, xb, yb);
    if (a + b == c || a + c == b || b + c == a) cout << "Yes" << '\n';
    else cout << "No" << '\n'; 
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}