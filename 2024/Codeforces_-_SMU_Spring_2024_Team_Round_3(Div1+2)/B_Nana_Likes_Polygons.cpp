/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-30 13:02:40 ms
 *
 * Problem: B. Nana Likes Polygons
 * Contest: Codeforces - SMU Spring 2024 Team Round 3(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/521164/problem/B
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define lb double
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

lb dis(lb x1, lb y1, lb x2, lb y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

lb tangle(lb x1, lb y1, lb x2, lb y2, lb x3, lb y3) {
    lb a = dis(x1, y1, x2, y2);
    lb b = dis(x2, y2, x3, y3);
    lb c = dis(x1, y1, x3, y3);
    lb x = (a * a + b * b - c * c) / (2 * a * b);
    return x * x;
}

lb area(lb x1, lb y1, lb x2, lb y2, lb x3, lb y3) {
    lb a = dis(x1, y1, x2, y2);
    lb b = dis(x2, y2, x3, y3);
    lb tab = sqrt(1 - tangle(x1, y1, x2, y2, x3, y3));
    lb c = dis(x1, y1, x3, y3);
    return a * b * tab / 2;

}

bool check(lb x1, lb y1, lb x2, lb y2, lb x3, lb y3) {
    lb k1 = (y1 - y2) * (x2 - x3);
    lb k2 = (y2 - y3) * (x1 - x2);
    return (k1 == k2);
}

void solve() {
    int n; cin >> n;
    vector<array<lb, 2>> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    lb ans = INF;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = j + 1; k <= n; k ++) {
                if (check(a[i][0], a[i][1], a[j][0], a[j][1], a[k][0], a[k][1])) continue;
                ans = min(ans, area(a[i][0], a[i][1], a[j][0], a[j][1], a[k][0], a[k][1]));
            }
        }
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << lf(10) << ans << '\n';
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