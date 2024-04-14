/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-14 20:24:35
 *
 * Problem: 小红的矩阵划分
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/80259/E
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==================================================================================
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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0, sum = 0;
    sum  += (n / 3) * (n / 2) * x * 2;
    if (n % 3 >= 2 && n >= 2) sum += y * (n / 2) + y * (n / 2 - 1);
    ans = max(ans, sum);
    sum = (n / 2) * (n / 2) * y;
    ans = max(ans, sum);
    cout << ans << '\n';
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