/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:29
 *
 * Problem: B. Card Game
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/B
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
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
    int ans = 0, r1 = 0, r2 = 0;
    if (a1 > a3) r1 ++;
    else if (a1 < a3) r2 ++;
    if (a2 > a4) r1 ++;
    else if (a2 < a4) r2 ++;
    if (r1 > r2) ans ++;

    r1 = 0, r2 = 0;
    if (a1 > a4) r1 ++;
    else if (a1 < a4) r2 ++;
    if (a2 > a3) r1 ++;
    else if (a2 < a3) r2 ++;
    if (r1 > r2) ans ++;

    r1 = 0, r2 = 0;
    if (a2 > a3) r1 ++;
    else if (a2 < a3) r2 ++;
    if (a1 > a4) r1 ++;
    else if (a1 < a4) r2 ++;
    if (r1 > r2) ans ++;

    r1 = 0, r2 = 0;
    if (a2 > a4) r1 ++;
    else if (a2 < a4) r2 ++;
    if (a1 > a3) r1 ++;
    else if (a1 < a3) r2 ++;
    if (r1 > r2) ans ++;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}