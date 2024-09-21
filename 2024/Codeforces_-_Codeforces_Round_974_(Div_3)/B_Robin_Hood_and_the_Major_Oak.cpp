/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-21 22:52:09
 *
 * Problem: B. Robin Hood and the Major Oak
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/B
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
    int n, k; cin >> n >> k;
    int x = k / 2;
    if (n & 1) {
        if (k & 1) {
            if (x & 1) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (x & 1) cout << "NO\n";
            else cout << "YES\n";
        }
    } else {
        if (x & 1) cout << "NO\n";
        else cout << "YES\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}