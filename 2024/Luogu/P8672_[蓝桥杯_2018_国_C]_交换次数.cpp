/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:31 ms
 *
 * Problem: P8672 [蓝桥杯 2018 国 C] 交换次数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8672?contestId=165868
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
    string s, str = "ABT"; cin >> s;
    map<char, int> mp;
    for (auto i : s) mp[i] ++;
    int ans = INF;
    do {
        string T;
        for (auto i : str) {
            for (int j = 0; j < mp[i]; j ++) T += i;
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != T[i]) cnt ++;
        }
        ans = min(ans, (cnt + 1) / 2);
    } while (next_permutation(str.begin(), str.end()));
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