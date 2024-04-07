/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 19:41:57 ms
 *
 * Problem: 小A的文化节
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/A
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
    map<int, int> mp;
    int ans = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        mp[i] = x;
    } 
    for (int i = 1, x; i <= m; i ++) {
        cin >> x;
        ans += mp[x];
    }
    cout << ans << endl;
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