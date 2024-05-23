/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:50
 *
 * Problem: F. Cutting Game
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/F
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int a, b, n, m; cin >> a >> b >> n >> m;
    int d = a + 1, u = 0, l = 0, r = b + 1;
    set<array<int, 2>> xx, yy;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        xx.insert({x, y});
        yy.insert({y, x});
    }
    // for (auto [x, y] : xx) debug2(x, y);
    // for (auto [y, x] : yy) debug2(y, x);
    int alice = 0, bob = 0;
    for (int i = 1; i <= m; i ++) {
        char c; int k;
        cin >> c >> k;
        if (c == 'U') {
            u += k;
            while (xx.size()) {
                auto [tx, ty] = *xx.begin();
                if (tx > u) break;
                xx.erase({tx, ty});
                yy.erase({ty, tx});
                if (i & 1) alice ++;
                else bob ++;
            }
        } else if (c == 'D') {
            d -= k;
            while (xx.size()) {
                auto [tx, ty] = *xx.rbegin();
                if (tx < d) break;
                xx.erase({tx, ty});
                yy.erase({ty, tx});
                if (i & 1) alice ++;
                else bob ++;
            }
        } else if (c == 'L') {
            l += k;
            while (yy.size()) {
                auto [ty, tx] = *yy.begin();
                if (ty > l) break;
                xx.erase({tx, ty});
                yy.erase({ty, tx});
                if (i & 1) alice ++;
                else bob ++;
            }
        } else {
            r -= k;
            while (yy.size()) {
                auto [ty, tx] = *yy.rbegin();
                if (ty < r) break;
                xx.erase({tx, ty});
                yy.erase({ty, tx});
                if (i & 1) alice ++;
                else bob ++;
            }
        }
    }
    cout << alice << ' ' << bob << '\n';
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