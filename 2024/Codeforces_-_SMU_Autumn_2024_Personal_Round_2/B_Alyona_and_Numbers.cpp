/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 12:22:39
 *
 * Problem: B. Alyona and Numbers
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i ++) {
        int x = (i + 4) / 5 * 5 - i;
        if (x == 0) x = 5;
        if (m >= x) ans += (m - x) / 5 + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}