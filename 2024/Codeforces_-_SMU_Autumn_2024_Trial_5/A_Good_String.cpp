/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-14 14:39:06
 *
 * Problem: A. Good String
 * Contest: Codeforces - SMU Autumn 2024 Trial 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549677/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int get(string s, char a, char b) {
    int ij = 1, cnt = 0;
    for (int i = 0, j = 1; j < s.size() && i < s.size(); ) {
        if (ij) {
            if (s[i] - '0' == a) ij ^= 1, j = i + 1;
            else i ++;
        } else if (!ij) {
            if (s[j] - '0' == b) ij ^= 1, i = j + 1, cnt ++;
            else j ++;
        }
    }
    return cnt;
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    map<char, int> mp;
    for (auto i : s) mp[i] ++;
    int ans = INF;
    for (auto [x, y] : mp) ans = min(ans, n - y);
    for (int i = 0; i <= 9; i ++) {
        for (int j = 0; j <= 9; j ++) {
            if (i == j) continue;
            ans = min(ans, n - get(s, i, j) * 2);
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