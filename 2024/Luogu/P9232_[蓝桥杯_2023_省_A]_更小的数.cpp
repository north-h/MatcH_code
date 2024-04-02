/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:32 ms
 *
 * Problem: P9232 [蓝桥杯 2023 省 A] 更小的数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9232?contestId=165469
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

int dp[N][N];

void solve() {
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for (int i = s.size() - 1; i >= 1; i --) {
        for (int j = i + 1; j < s.size(); j ++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else if (s[i] < s[j]) dp[i][j] = 0;
            else dp[i][j] = 1;
            if (dp[i][j]) ans ++;
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