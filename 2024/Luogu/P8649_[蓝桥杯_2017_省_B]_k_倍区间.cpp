/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:35 ms
 *
 * Problem: P8649 [蓝桥杯 2017 省 B] k 倍区间
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8649?contestId=165868
 * MemoryL: 256 MB
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
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    map<int, int> mp;
    ll ans = 0, cnt = 0;
    mp[0] = 1;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        sum += x;
        sum %= k;
        ans += mp[sum];
        mp[sum] ++;
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