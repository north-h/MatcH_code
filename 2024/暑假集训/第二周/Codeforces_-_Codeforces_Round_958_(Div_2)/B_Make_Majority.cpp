/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-15 22:36:45
 *
 * Problem: B. Make Majority
 * Contest: Codeforces - Codeforces Round 958 (Div. 2)
 * URL:     https://codeforces.com/contest/1988/problem/B
 * MemoryL: 512 MB
 * TimeL:   1500 ms
 * ==================================================================================
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
    int n; string s;
    cin >> n >> s;
    if (n == 1) {
        if (s[0] == '0') cout << "No" << '\n';
        else cout << "Yes" << '\n';
        return ;
    }
    if (n == 2) {
        if (s == "11") cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return ;
    }
    int c0 = 0, c1 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '1') c1 ++;
    }
    for (int i = 0; i < s.size(); i ++) {
        int j = i;
        if (s[i] != '0') continue;
        while (s[j] == '0' && j < s.size()) j ++;
        i = j - 1;
        c0 ++;
    }
    if (c1 > c0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}