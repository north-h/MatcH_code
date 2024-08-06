/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:38
 *
 * Problem: D. Slavic's Exam
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    string s, t; cin >> s >> t;
    for (int i = 0, j = 0; i < s.size() && j < t.size(); i ++) {
        if (s[i] == t[j]) j ++;
        else {
            if (s[i] == '?') s[i] = t[j ++];
        }
    }
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '?') s[i] = 'a';
    }
    int j = 0;
    for (int i = 0; i < s.size() && j < t.size(); i ++) {
        if (s[i] == t[j]) j ++;
    }
    if (j == (int)t.size()) {
        cout << "YES" << '\n';
        cout << s << '\n';
    } else cout << "NO" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}