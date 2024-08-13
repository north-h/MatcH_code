/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-13 22:41:13
 *
 * Problem: B. Seating in a Bus
 * Contest: Codeforces - Codeforces Round 966 (Div. 3)
 * URL:     https://codeforces.com/contest/2000/problem/B
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
    int n; cin >> n;
    map<int, int> vis;
    bool ok = true;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        // debug2(x, n);
        if (i == 1) {
            vis[x] = 1;
            continue;
        }
        if (x == 1) {
            if (vis[x + 1]) vis[x] = 1;
            else {
                ok = false;
            }
        } else if (x == n) {
            if (vis[x - 1]) vis[x] = 1;
            else {
                ok = false;
            }
        } else {
            if (vis[x - 1] || vis[x + 1]) vis[x] = 1;
            else {
                ok = false;
            }
        }
    }
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