/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-20 22:35:51
 *
 * Problem: A. Zhan's Blender
 * Contest: Codeforces - Codeforces Round 973 (Div. 2)
 * URL:     https://codeforces.com/contest/2013/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    cout << max((n + x - 1) / x, (n + y - 1) / y) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}