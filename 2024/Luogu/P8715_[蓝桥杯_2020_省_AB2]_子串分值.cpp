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
    s = '#' + s;
    int n = s.size();
    map<char, vector<int>> mp;
    for (char op = 'a'; op <= 'z'; op ++) mp[op].push_back(0);
    for (int i = 1; i <= n; i ++) {
        mp[s[i]].push_back(i);
    }
    for (char op = 'a'; op <= 'z'; op ++) mp[op].push_back(n);
    int ans = 0;
    for (char op = 'a'; op <= 'z'; op ++) {
        for (int i = 1; i < mp[op].size() - 1; i ++) {
            ans += (mp[op][i] - mp[op][i - 1]) * (mp[op][i + 1] - mp[op][i]);
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