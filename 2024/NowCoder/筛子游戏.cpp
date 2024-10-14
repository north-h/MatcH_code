/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 21:07:45
 *
 * Problem: 筛子游戏
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/28263/D
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

void solve() {
    int n, k1, k2, k3, a, b, c;
    cin >> n >> k1 >> k2 >> k3 >> a >> b >> c;
    double cv = 0;
    for (int i = 1; i <= k1; i ++) {
        for (int j = 1; j <= k2; j ++) {
            for (int k = 1; k <= k3; k ++) {
                if (i == a || j == b || k == c) continue;
                cv += (i + j + k);
            }
        }
    }
    cv /= (k1 * k2 * k3);
    debug1(cv);
    cout << fixed << setprecision(10) << n / cv << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}