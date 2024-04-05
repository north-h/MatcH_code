/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:26 ms
 *
 * Problem: P8630 [蓝桥杯 2015 国 B] 密文搜索
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8630?contestId=165868
 * MemoryL: 512 MB
 * TimeL:   3000 ms
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
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    map<string, int> mp;
    for (int i = 1; i <= n; i ++) {
        string sans;
        cin >> sans;
        sort(sans.begin(), sans.end());
        mp[sans] ++;
    }
    for (int i = 0; i < s.size(); i ++) {
        string str = s.substr(i, 8);
        sort(str.begin(), str.end());
        ans += mp[str];
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