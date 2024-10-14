/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 19:24:06
 *
 * Problem: G. Tokitsukaze and Good 01-String (hard version)
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/G
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
    string s, ss; cin >> s;
    int c = 0, v = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) c ++, ss += '#';
        else ss += s[i];
    }
    // cout << ss << '\n';
    auto f = ss.front();
    for (int i = 1; i < ss.size(); i ++) {
        if (f == ss[i] || ss[i] == '#' || f == '#') {
            if (ss[i] != '#') f = ss[i];
            continue;
        }
        f = ss[i];
        v ++;
    }
    cout << c << ' ' << v + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
