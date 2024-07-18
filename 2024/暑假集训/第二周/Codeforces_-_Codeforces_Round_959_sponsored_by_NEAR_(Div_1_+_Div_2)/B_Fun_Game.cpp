/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-18 22:36:23
 *
 * Problem: B. Fun Game
 * Contest: Codeforces - Codeforces Round 959 sponsored by NEAR (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1994/problem/B
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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) {
        cout << "YES" << '\n';
        return ;
    }
    bool ok = false;
    int p = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '1') {
            p = i;
            ok = true;
            break;
        }
    }
    // debug1(p);
    for (int i = 0; i < p; i ++) {
        if (s[i] != t[i]) ok = false;
    }
    if (s[0] == '0' && t[0] == '1') ok = false;
    // debug2(s[0], t[0]);
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    // while (true) {
    //     debug2(s, t);
    //     int l = -1, r = -1;
    //     string st = s;
    //     for (int i = 0; i < s.size(); i ++) {
    //         if (s[i] != t[i]) {
    //             l = i;
    //             break;
    //         }
    //     }
    //     for (int i = s.size() - 1; i >= 0; i --) {
    //         if (s[i] != t[i]) {
    //             r = i;
    //             break;
    //         }
    //     }
    //     if (l == -1) l = r;
    //     if (r == -1) r = l;
    //     debug2(l, r);
    //     for (int i = l; i <= r; i ++) {
    //         int x = s[i] - '0', y = s[i - l] - '0', z = (x ^ y);
    //         debug2(x, y);
    //         debug1(z);
    //         s[i] = (z + '0');
    //     }
    //     if (t == s) {
    //         cout << "YES" << '\n';
    //         return ;
    //     }
    //     debug2(st, s);
    //     if (st == s) break;
    // }
    // cout << "NO" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}