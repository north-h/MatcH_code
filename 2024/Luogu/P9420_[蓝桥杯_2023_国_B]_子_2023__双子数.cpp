/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:33 ms
 *
 * Problem: P9420 [蓝桥杯 2023 国 B] 子 2023 / 双子数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9420?contestId=173756
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
const int N = 5000100;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    char t; cin >> t;
    // string s;
    // for (int i = 1; i <= 2023; i ++) {
    //     s += to_string(i);
    // }
    // ll v1 = 0, v2 = 0, v3 = 0, v4 = 0;
    // for (auto i : s) {
    //     if (i == '2') v1 ++, v3 += v2;
    //     else if (i == '0') v2 += v1;
    //     else if (i == '3') v4 += v3;
    // }
    if (t == 'A') cout << 5484660609 << '\n';
    // vector<int> vis(N), prime;
    // for (int i = 2; i < N; i ++) {
    //     if (vis[i]) continue;
    //     for (int j = i + i; j < N; j += i) {
    //         vis[j] = 1;
    //     }
    // }
    // for (int i = 2; i < N; i ++) {
    //     if (!vis[i]) prime.push_back(i);
    // }
    // cout << prime.size() << '\n';
    // int ans = 0;
    // for (int i = 0; i < prime.size() - 1; i ++) {
    //     ll y = (ll)prime[i] * prime[i] * prime[i] * prime[i];
    //     if (y > 23333333333333) break;
    //     for (int j = i + 1; j < prime.size(); j ++) {
    //         // debug2(prime[i], prime[j]);
    //         ll x = (ll)prime[i] * prime[i] * prime[j] * prime[j];
    //         if (x > 23333333333333) break;
    //         if (x >= 2333 && x <= 23333333333333) ans ++;
    //     }
    // }
    // cout << v4 << ' ' << ans << '\n';
    if (t == 'B') cout << 947293 << '\n';
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