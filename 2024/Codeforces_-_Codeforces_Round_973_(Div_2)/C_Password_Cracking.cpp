/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-20 22:35:53
 *
 * Problem: C. Password Cracking
 * Contest: Codeforces - Codeforces Round 973 (Div. 2)
 * URL:     https://codeforces.com/contest/2013/problem/C
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

void solve() {
    int n; cin >> n;
    string s1;
    for (int i = 1; i <= n && (int)s1.size() < n; i ++) {
        s1 += '0';
        cout << '?' << ' ' << s1 << endl;
        int f; cin >> f;
        if (f == 1) continue;
        s1.pop_back();
        s1 += '1';
        cout << '?' << ' ' << s1 << endl;
        cin >> f;
        if (f == 0) {
            s1.pop_back();
            break;
        }
    }
    for (int i = 1; i <= n && (int)s1.size() < n; i ++) {
        s1 = '0' + s1;
        cout << '?' << ' ' << s1 << endl;
        int f; cin >> f;
        if (f == 1) continue;
        s1 = s1.substr(1);
        s1 = '1' + s1;
    }
    cout << '!' << ' ' << s1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}