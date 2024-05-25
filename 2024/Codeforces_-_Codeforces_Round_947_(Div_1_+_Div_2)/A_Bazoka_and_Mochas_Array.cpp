/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-25 22:43:04
 *
 * Problem: A. Bazoka and Mocha's Array
 * Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1975/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int cv = 0;
    for (int i = 2; i <= n; i ++) {
        if (a[i - 1] > a[i]) cv ++;
    }
    if (cv == 1 && a[1] >= a[n] || cv == 0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}