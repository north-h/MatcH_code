/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:23 ms
 *
 * Problem: P9242 [蓝桥杯 2023 省 B] 接龙数列
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9242?contestId=165469
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(10);
    for (int i = 1; i <= n; i ++) {
        string bs;cin >> bs;
        int f = bs.front(), b = bs.back();
        dp[b - '0'] = max(dp[f - '0'] + 1, dp[b - '0']);
    }
    cout << n - *max_element(dp.begin(), dp.end()) << endl;
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