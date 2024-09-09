/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-07 12:06:58
 *
 * Problem: B. Creep
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548070/problem/B
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
    int a, b; cin >> a >> b;
    if (a > b) {
        for (int i = 1; i <= b; i ++) cout << "10";
        for (int i = 1; i <= a - b; i ++) cout << "0";
    } else {
        for (int i = 1; i <= a; i ++) cout << "01";
        for (int i = 1; i <= b - a; i ++) cout << "1";
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}