/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-07 14:25:56 ms
 *
 * Problem: E. Secret Box
 * Contest: Codeforces - Codeforces Round 952 (Div. 4)
 * URL:     https://codeforces.com/contest/1985/problem/E
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
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
    int x, y, z, k; cin >> x >> y >> z >> k;
    int ans = 0;
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= y; j ++) {
            int kk = k / (i * j);
            if (kk > z || k % (i * j)) continue;
            // debug2(i, j);
            // debug1(kk);
            ans = max(ans, (x - i + 1) * (y - j + 1) * (z - kk + 1));
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}