/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-06 20:36:18 ms
 *
 * Problem: A - Penalty Kick
 * Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
 * URL:     https://atcoder.jp/contests/abc348/tasks/abc348_a
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 20:25:18 ms
 *
 * Problem: 小A的任务
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/E
 * MemoryL: 524288 MB
 * TimeL:   6000 ms
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
    for (int i = 1; i <= n; i ++) {
        if (i % 3 == 0) cout << 'x';
        else cout << 'o';
    }
    cout << endl;
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