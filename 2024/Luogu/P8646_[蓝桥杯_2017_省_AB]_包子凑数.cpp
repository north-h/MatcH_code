/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:44 ms
 *
 * Problem: P8646 [蓝桥杯 2017 省 AB] 包子凑数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8646?contestId=165868
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(N);
    bool f1 = false, f2 = false;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] & 1) f1 = true;
        if (a[i] % 2 == 0) f2 = true;
    }
    if (!(f1 && f2)) {
        cout << "INF" << endl;
        return ;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = a[i]; j < N; j ++) {
            dp[j] |= dp[j - a[i]];
        }
    }
    int ans = 0;
    for (int i = 1; i < N; i ++) ans += !dp[i];
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