/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:48 ms
 *
 * Problem: P9236 [蓝桥杯 2023 省 A] 异或和之和
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9236?contestId=165868
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
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] ^= s[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            ans += s[j] ^ s[i - 1];
        }
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