/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-11 17:15:06
 *
 * Problem: B. Alice's Adventures in Permuting
 * Contest: Codeforces - Codeforces Round 986 (Div. 2)
 * URL:     https://codeforces.com/contest/2028/problem/B
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
    int n, b, c; cin >> n >> b >> c;
    if (c > n - 1) {
        cout << n << '\n';
        return ;
    }
    if (n == 1) {
        if (c == 0) cout << 0 << '\n';
        else cout << 1 << '\n';
        return ;
    }
    if (n == 2 && b == 0 && c == 0) {
        cout << 1 << '\n';
        return ;
    } 
    if (b == 0) {
        if (c == 0 || n > c + 2) cout << -1 << '\n';
        else cout << n - 1 << '\n';
        return ;
    }
    int tp = (n - 1 - c) / b + 1;
    cout << n - tp << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}