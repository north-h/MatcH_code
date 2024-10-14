/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-14 17:02:30
 *
 * Problem: I. Changing Brackets
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/I
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    string s; cin >> s; s = " " + s;
    int sz = s.size();
    vector<int> odd(sz + 1), even(sz + 1);
    for (int i = 1; i < sz; i ++) {
        if (s[i] == '(' || s[i] == ')') {
            if (i & 1) odd[i] = 1;
            else even[i] = 1;
        }
    }
    // for (int i = 1; i <= sz; i ++) cout << odd[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= sz; i ++) cout << even[i] << ' ';
    // cout << '\n';
    for (int i = 1; i < sz; i ++) {
        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
    }
    int q; cin >> q;
    while (q --) {
        int l, r; cin >> l >> r;
        int a = odd[r] - odd[l - 1];
        int b = even[r] - even[l - 1];
        // debug2(a, b);
        if (a == b) {
            cout << 0 << '\n';
        } else {
            cout << abs(a - b) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}