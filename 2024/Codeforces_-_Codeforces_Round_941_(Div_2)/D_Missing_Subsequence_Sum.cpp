/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-28 08:49:06
 *
 * Problem: D. Missing Subsequence Sum
 * Contest: Codeforces - Codeforces Round 941 (Div. 2)
 * URL:     https://codeforces.com/contest/1966/problem/D
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
    int n, k; cin >> n >> k;
    set<int> num;
    int b = 0;
    while ((1 << b) < k) num.insert(1 << b), b ++;
    if (k - (1 << (b - 1)) - 1 > 0) num.insert(k - (1 << (b - 1)) - 1);
    if (k + 1 <= n) num.insert(k + 1);
    while ((1 << b) <= n && (1 << b) != k) num.insert(1 << b), b ++;
    // // // debug1(b);
    // if (n - (1 << (b - 1)) > 0) num.insert(n - (1 << (b - 1)));
    for (auto i : num) cout << i << ' ';
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