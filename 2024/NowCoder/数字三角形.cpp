/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 15:23:07
 *
 * Problem: 数字三角形
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/93674/K
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int g[30][30];

void solve() {
    // cout << 0 << '\n';
    cout << 21 << '\n';
    for (int i = 1; i <= 22; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (j & 1) g[i][j] = 0;
            else g[i][j] = (1 << (22 - i));
        }
    }
    for (int i = 2; i <= 22; i ++) {
        for (int j = 1; j < i; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
    int t; cin >> t;
    while (t --) {
        int sum; cin >> sum;
        // debug1(sum);
        int x = 2, y = 1;
        for (int i = 1; i < 21; i ++) {
            // debug2(x, y);
            if (g[x + 1][y + 1]) {
                if (sum >= g[x + 1][y + 1]) {
                    sum -= g[x + 1][y + 1];
                    cout << "R";
                    x ++;
                    y ++;
                } else {
                    x ++;
                    cout << "L";
                }
            } else {
                if (sum >= g[x + 1][y]) {
                    sum -= g[x + 1][y];
                    cout << "L";
                    x ++;
                } else {
                    x ++;
                    y ++;
                    cout << "R";
                }
            }
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}