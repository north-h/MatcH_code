/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-06 11:55:12
 *
 * Problem: C. Bitwise Balancing
 * Contest: Codeforces - Codeforces Round 976 (Div. 2) and Divide By Zero 9.0
 * URL:     https://codeforces.com/problemset/problem/2020/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    for (int i = 1; i <= 10; i ++) {
        for (int j = 1; j <= 10; j ++) {
            for (int k = 1; k <= 10; k ++) {
                for (int l = 1; l <= 10000; l ++) {
                    if ((l | i) - (l & j) == k) {
                        cout << i << ' ' << j << ' ' << k << ':' << l << '\n';
                        break;
                    }
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}