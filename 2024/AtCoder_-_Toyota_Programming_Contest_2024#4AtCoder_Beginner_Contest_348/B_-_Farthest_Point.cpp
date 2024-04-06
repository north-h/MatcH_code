/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-06 20:36:22 ms
 *
 * Problem: B - Farthest Point
 * Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
 * URL:     https://atcoder.jp/contests/abc348/tasks/abc348_b
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using i2 = array<int, 2>;

void solve() {
    int n;
    cin >> n;
    vector<i2> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    auto check = [&](int x1, int y1, int x2, int y2) -> double {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    for (int i = 1; i <= n; i ++) {
        double ans = 0;
        int id;
        for (int j = 1; j <= n; j ++) {
            if (i == j) continue;
            double dis = check(a[i][0], a[i][1], a[j][0], a[j][1]);
            if (dis > ans) {
                ans = dis;
                id = j;
            }
        }
        cout << id << endl;
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}