/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 13:14:23
 *
 * Problem: 三点共线
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/93674/G
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

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y1 - y2) * (x3 - x2) == (x1 - x2) * (y3 - y2);
}

void solve() {
    vector<array<int, 2>> p;
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        p.push_back({x, y});
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i == j) continue;
            for (int k = 0; k < n; k ++) {
                if (i == k || j == k) continue;
                if (check(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1])) {
                    cout << "Yes\n";
                    return ;
                }
            }
        }
    }
    cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}