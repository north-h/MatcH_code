/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-28 22:46:50
 *
 * Problem: F. 0, 1, 2, Tree!
 * Contest: Codeforces - Codeforces Round 937 (Div. 4)
 * URL:     https://codeforces.com/contest/1950/problem/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = log2(a + 1);
    int c = (1 << d) + a - (1)
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