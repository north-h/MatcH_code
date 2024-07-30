/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-30 22:37:33
 *
 * Problem: A. Strong Password
 * Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1997/problem/A
 * MemoryL: 512 MB
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
    string s; cin >> s;
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == s[i - 1]) {
            char op;
            if (s[i] == 'z') op = 'a';
            else op = (char)(s[i] + 1);
            s = s.substr(0, i) + op + s.substr(i);
            cout << s << '\n';
            return ;
        }
    }
    cout << s;
    if (s.back() == 'z') cout << 'a' << '\n';
    else cout << (char)(s.back() + 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}