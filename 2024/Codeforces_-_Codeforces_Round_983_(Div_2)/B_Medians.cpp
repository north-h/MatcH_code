/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-01 22:45:19
 *
 * Problem: B. Medians
 * Contest: Codeforces - Codeforces Round 983 (Div. 2)
 * URL:     https://codeforces.com/contest/2032/problem/B
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
    if (k == 1 && n == 1) cout << 1 << '\n' << 1 << '\n';
    else if (k == 1 || k == n) cout << -1 << '\n';
    else {
        if (k % 2 == 0) {
            cout << 3 << '\n';
            cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
        } else {
            cout << 5 << '\n';
            cout << 1 << ' ' << 2 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
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