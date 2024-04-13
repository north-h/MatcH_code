/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-13 22:35:31
 *
 * Problem: A. Nene's Game
 * Contest: Codeforces - Codeforces Round 939 (Div. 2)
 * URL:     https://codeforces.com/contest/1956/problem/A
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
    int k, q;
    cin >> k >> q;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    while (q --) {
        int x;
        cin >> x;
        cout << min(x, a[1] - 1) << ' ';
    }
    cout << '\n';
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