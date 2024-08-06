/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:51
 *
 * Problem: G1. Ruler (easy version)
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/G1
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int l = 1, r = 999, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        cout << '?' << ' ' << mid << ' ' << mid << endl;
        cout << endl;
        int s; cin >> s;
        if (mid * mid != s) r = mid - 1;
        else l = mid + 1, ans = mid;
    }
    cout << '!' << ' ' << ans + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}