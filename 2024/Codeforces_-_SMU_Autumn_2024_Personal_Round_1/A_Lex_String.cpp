/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-07 12:06:54
 *
 * Problem: A. Lex String
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548070/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    string c;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int cnta = 0, cntb = 0;
    while (a.size() && b.size()) {
        if (a.back() > b.back()) {
            if (cntb < k) {
                cnta = 0, cntb ++;
                c += b.back();
                b.pop_back();
            } else {
                cntb = 0; cnta ++;
                c += a.back();
                a.pop_back();
            }
        } else {
            if (cnta < k) {
                cntb = 0, cnta ++;
                c += a.back();
                a.pop_back();
            } else {
                cnta = 0; cntb ++;
                c += b.back();
                b.pop_back();
            }
        }
    }
    cout << c << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}