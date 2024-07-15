/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-15 22:36:40
 *
 * Problem: A. Split the Multiset
 * Contest: Codeforces - Codeforces Round 958 (Div. 2)
 * URL:     https://codeforces.com/contest/1988/problem/A
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==================================================================================
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

void solve() {
    int n, k; cin >> n >> k;
    cout << (n - 1 + k - 2) / (k - 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}