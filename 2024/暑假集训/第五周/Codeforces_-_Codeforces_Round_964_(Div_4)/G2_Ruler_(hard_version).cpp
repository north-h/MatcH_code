/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:55
 *
 * Problem: G2. Ruler (hard version)
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/G2
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
        int midl = l + (r - l) / 3;
        int midr = r - (r - l) / 3;
        cout << '?' << ' ' << midl << ' ' << midr << endl;
        int s = midl * midr;
        int x; cin >> x;
        if (x == midl * midr) l = midr + 1, ans = midr;
        else if (x == (midl + 1) * (midr + 1)) r = midl - 1;
        else l = midl + 1, r = midr - 1, ans = midl;
    }
    cout << '!' << ' ' << ans + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}