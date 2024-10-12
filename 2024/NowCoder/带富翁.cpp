/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-12 21:29:07
 *
 * Problem: 带富翁
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/28263/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<double> dp(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        for (int x = 1; x <= 6; x ++) {
            for (int j = i + x; j <= n; j += x) {
                dp[j] = dp[i] + 1.0 / 6 * a[j];
            }
            for (int j = 1; j <= n; j ++) cout << dp[i] << ' ';
            cout << '\n';
        }
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}