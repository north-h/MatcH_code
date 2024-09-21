/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-13 20:17:42
 *
 * Problem: A. Stand-up Comedian
 * Contest: Codeforces - SMU Autumn 2024 Trial 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549118/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == 0) {
        cout << 1 << '\n';
        return ;
    }
    if (a2 > a3) swap(a2, a3);
    int ans = a1 + min(a2, a3) * 2;
    // debug1(ans);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}