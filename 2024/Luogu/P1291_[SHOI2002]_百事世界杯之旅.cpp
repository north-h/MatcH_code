/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 21:51:37
 *
 * Problem: P1291 [SHOI2002] 百事世界杯之旅
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1291
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

array<int, 2> calc(int fz1, int fm1, int fz2, int fm2) {
    int m = fm1 * fm2;
    int z = (fz1 * fm2 + fz2 * fm1);
    int g = __gcd(z, m);
    return {z / g, m / g};
}

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> dp(n + 1);
    dp[1] = {1, 1};
    for (int i = 2; i <= n; i ++) {
        dp[i] = calc(dp[i - 1][0], dp[i - 1][1], n, n - i + 1);
    }
    auto [z, m] = dp[n];
    int x = z / m;
    z = z % m;
    int sz = max(to_string(z).size(), to_string(m).size());
    int ss = to_string(x).size();
    if (z == 0) {
        cout << x << '\n';
        return ;
    }
    for (int i = 1; i <= ss; i ++) cout << ' '; cout << z << '\n';
    cout << x; for (int i = 1; i <= sz; i ++) cout << '-'; cout << '\n';
    for (int i = 1; i <= ss; i ++) cout << ' '; cout << m << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}