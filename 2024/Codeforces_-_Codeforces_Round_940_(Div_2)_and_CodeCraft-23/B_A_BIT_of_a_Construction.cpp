/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-21 22:41:09
 *
 * Problem: B. A BIT of a Construction
 * Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
 * URL:     https://codeforces.com/contest/1957/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return ;
    }
    int sum = 0;
    for (int i = 1; sum + i <= k; i *= 2) {
        sum += i;
    }
    cout << sum << ' ' << k - sum << ' ';
    for (int i = 1; i <= n - 2; i ++) cout << 0 << " \n"[i == n - 2];
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