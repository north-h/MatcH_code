/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:54 ms
 *
 * Problem: P10429 [蓝桥杯 2024 省 B] 拔河
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P10429?contestId=173756
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==============================================================
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
    int n; cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll res = LLONG_MAX;
    for (int i = 1; i < n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            int l = i, r = j;
            ll sl = a[i], sr = a[j];
            res = min(res, abs(sl - sr));
            while (l > 1 && r < n) {
                if (sl > sr && l) {
                    sr += a[r ++];
                    res = min(res, abs(sl - sr));
                } else {
                    sl += s[l --];
                    res = min(res, abs(sl - sr));
                }
            }
            while (l > 1) {
                sl += s[l --];
                res = min(res, abs(sl - sr));
            }

            while (r < n) {
                sr += s[r ++];
                res = min(res, abs(sl - sr));
            }
        }
    }
    cout << res << '\n';
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