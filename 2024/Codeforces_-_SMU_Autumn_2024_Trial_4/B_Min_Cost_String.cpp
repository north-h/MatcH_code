/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-13 11:14:03
 *
 * Problem: B. Min Cost String
 * Contest: Codeforces - SMU Autumn 2024 Trial 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549671/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

// abcd
void solve() {
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i ++) {
        for (int j = i + 1; j < s.size() - 1; j ++) {
            if (s[i] == s[j] && s[i + 1] == s[j + 1]) ans ++;
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