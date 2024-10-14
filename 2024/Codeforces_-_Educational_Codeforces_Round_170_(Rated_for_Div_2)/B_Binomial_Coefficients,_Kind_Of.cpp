/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-10-14 22:54:03
 *
 * Problem: B. Binomial Coefficients, Kind Of
 * Contest: Codeforces - Educational Codeforces Round 170 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/2025/problem/B
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;


using namespace std;

void solve() {
    vector<int> a(N, 1);
    for (int k = 1; k < N; k++) {
        a[k] = (a[k - 1] * 2) % MOD;
    }

    int t;
    cin >> t;

    vector<int> n(t);
    for (int i = 0; i < t; i++) cin >> n[i];

    vector<int> k(t);
    for (int i = 0; i < t; i++) cin >> k[i];

    for (int i = 0; i < t; i++) {
        cout << a[k[i]] << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}