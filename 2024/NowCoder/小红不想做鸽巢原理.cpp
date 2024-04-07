/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-07 23:27:39
 *
 * Problem: 小红不想做鸽巢原理
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78904/B
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
     int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        sum %= k;
    }
    if (sum == 0) {
        cout << 0 << endl;
        return ;
    }
    sort(a.rbegin(), a.rend());
    int c = 0;
    for (int i = 1; i <= n; i ++) {
        c += a[i];
        if (c >= sum) {
            cout << i << endl;
            return ;
        }
    }
    cout << n << endl;
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