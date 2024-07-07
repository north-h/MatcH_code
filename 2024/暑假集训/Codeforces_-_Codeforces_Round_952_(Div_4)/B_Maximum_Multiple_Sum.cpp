/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-07 14:25:43 ms
 *
 * Problem: B. Maximum Multiple Sum
 * Contest: Codeforces - Codeforces Round 952 (Div. 4)
 * URL:     https://codeforces.com/contest/1985/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0, sum = 0;;
    for (int i = 2; i <= n; i ++) {
        int cnt = (i + n / i * i) * (n / i) / 2;
        if (sum < cnt) {
            sum = cnt;
            ans = i;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}