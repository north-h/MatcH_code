/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-11-02 12:34:51
 *
 * Problem: F. Colorful Balloons
 * Contest: Codeforces - SMU Autumn 2024 Team Round 11
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/563273/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; i ++) {
        string s; cin >> s;
        mp[s] ++;
    }
    for (auto [x, y] : mp) {
        if (y > n / 2) {
            cout << x << '\n';
            return ;
        }
    }
    cout << "uh-oh" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}