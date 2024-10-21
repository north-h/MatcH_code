/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-21 21:33:33
 *
 * Problem: A. Profitable Interest Rate
 * Contest: Codeforces - Codeforces Round 980 (Div. 2)
 * URL:     https://codeforces.com/contest/2024/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a >= b) cout << a << '\n';
    else {
        int x = b - a;
        cout << max(0ll, a - x) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}