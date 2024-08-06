/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:34
 *
 * Problem: C. Showering
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int n, s, m; cin >> n >> s >> m;
    int lst = 0;
    bool ok = false;
    for (int i = 1; i <= n; i ++) {
        int l, r; cin >> l >> r;
        if (l - lst >= s) ok = true;
        lst = r;
    }
    if (m - lst >= s) ok = true;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}