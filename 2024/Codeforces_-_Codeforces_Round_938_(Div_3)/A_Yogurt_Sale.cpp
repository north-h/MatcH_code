/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-08 23:53:46
 *
 * Problem: A. Yogurt Sale
 * Contest: Codeforces - Codeforces Round 938 (Div. 3)
 * URL:     https://codeforces.com/contest/1955/problem/A
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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = INF;
    for (int i = 0; i * 2 <= n; i ++) {
        ans = min(ans, b * i + (n - i * 2) * a);
    }
    cout << ans << endl;
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