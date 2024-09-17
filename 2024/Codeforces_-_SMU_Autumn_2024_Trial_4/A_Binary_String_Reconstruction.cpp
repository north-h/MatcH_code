/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-13 11:14:02
 *
 * Problem: A. Binary String Reconstruction
 * Contest: Codeforces - SMU Autumn 2024 Trial 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549671/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s; cin >> s;
    string w = s;
    for (auto &i : w) i = '#';
    int x; cin >> x;
    for (int i = 0; i < (int)s.size(); i ++) {
        if (s[i] == '0') {
            if (i - x < 0 && i + x >= (int)s.size()) {
                w[i] = '0';
                continue;
            }
            if (i - x < 0) {
                if (w[i + x] == '1') {
                    cout << -1 << '\n';
                    return ;
                }
                w[i + x] = '0';
            } else if (i + x >= (int)w.size()) {
                // cout << "---\n";
                if (w[i - x] == '1') {
                    cout << -1 << '\n';
                    return ;
                }
                w[i - x] = '0';
            } else {
                if (w[i - x] == '1' || w[i + x] == '1') {
                    cout << -1 << '\n';
                    return ;
                }
                w[i - x] = w[i + x] = '0';
            }
        } else {
             if (i - x < 0 && i + x >= (int)s.size()) {
                cout << -1 << '\n';
                return ;
            }
            if (i - x < 0 ) {
                if (w[i + x] == '0') {
                    cout << -1 << '\n';
                    return ;
                }
                w[i + x] = '1';
            } else if (i + x >= (int)w.size()) {
                if (w[i - x] == '0') {
                    cout << -1 << '\n';
                    return ;
                }
                w[i - x] = '1';
            } else {
                if (w[i - x] == '0' && w[i + x] == '0') {
                    cout << -1 << '\n';
                    return ;
                }
                if (w[i - x] == '0') w[i + x] = '1';
                else w[i - x] = '1';
            }
        }
        // cout << "w:" << w << '\n';
        // cout << "s:" << s << '\n';
        // cout << '\n';
    }
    for (auto & i : w) if (i == '#') i = '1';
    cout << w << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}