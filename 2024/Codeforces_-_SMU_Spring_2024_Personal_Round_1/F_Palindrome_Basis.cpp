/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:49 ms
 *
 * Problem: F. Palindrome Basis
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


using namespace std;
using ll = long long;

vector<int> a;
vector<int> dp(40005, 0);

void solve() {
    int n; cin >> n;
    cout << dp[n] << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i <= 5; i ++) {
        string s1 = to_string(i);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) a.push_back(i);
    }
    dp[0] = 1;
    for (auto i : a) {
        for (int j = i; j <= 5; j ++) {
            dp[j] += dp[j - i];
            dp[j] = max(dp[j], dp[j - i]);
            dp[j] %= mod;
        }
        for (int i = 1; i <= 5; i ++) cout << dp[i] << " \n"[i == 5];
    }
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}