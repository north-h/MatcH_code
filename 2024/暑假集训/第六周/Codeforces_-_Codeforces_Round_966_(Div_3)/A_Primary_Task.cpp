/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-13 22:41:09
 *
 * Problem: A. Primary Task
 * Contest: Codeforces - Codeforces Round 966 (Div. 3)
 * URL:     https://codeforces.com/contest/2000/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    string s; cin >> s;
    if (s.size() > 2 && s[0] == '1' && s[1] == '0' && ((s.size() == 3 && s[2] > '1') || ( s.size() > 3 && s[2] != '0'))) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}