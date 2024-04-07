/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 19:44:39 ms
 *
 * Problem: 小A的游戏
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/B
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n % 3 == m % 3) cout << "Yes" << endl;
    else cout << "No" << endl;
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