/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-09 14:28:06
 *
 * Problem: D. Vus the Cossack and a Contest
 * Contest: Codeforces - SMU Autumn 2024 Trial 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548611/problem/D
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
    int n, m, k; cin >> n >> m >> k;
    if (min(m, k) >= n) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}