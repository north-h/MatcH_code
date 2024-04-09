/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:22 ms
 *
 * Problem: P8715 [蓝桥杯 2020 省 AB2] 子串分值
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8715?contestId=166591
 * MemoryL: 128 MB
 * TimeL:   1000 ms
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

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i ++) {
        for (int j = i; j < s.size(); j ++) {
            unordered_map<char, int> mp;
            for (int k = i; k <= j; k ++) mp[s[k]] ++;
            for (auto [x, y] : mp) ans += (y == 1);
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