/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:46 ms
 *
 * Problem: P8669 [蓝桥杯 2018 省 B] 乘积最大
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8669?contestId=173756
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int mod = 1000000009;
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll res = 1;
    int l = 1, r = n;
    int cnt = k / 2 * 2;
    while (cnt) {
        ll c1 = (ll)a[l] * a[l + 1], c2 = (ll)a[r] * a[r - 1];
        if (res * c1 > res * c2) {
            res *= c1;
            cnt -= 2;
            l += 2;
        } else {
            res *= c2;
            cnt -= 2;
            r -= 2;
        }
    }
    ll ans = res;
    if (k & 1) {
        for (int i = l; i <= r; i ++) {
            if (i == l) ans = res * a[i];
            else ans = max(ans, res * a[i]);
        }
    }
    // debug2(ans, res);
    if (ans < 0) cout << (0 - ((0 - ans) % mod)) << '\n';
    else cout << ans % mod << '\n';
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