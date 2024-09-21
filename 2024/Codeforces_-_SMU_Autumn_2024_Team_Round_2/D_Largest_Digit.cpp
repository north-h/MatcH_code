/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-21 12:35:07
 *
 * Problem: D. Largest Digit
 * Contest: Codeforces - SMU Autumn 2024 Team Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551542/problem/D
 * MemoryL: 1024 MB
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

int f(int x) {
    int res = 0;
    while (x) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}

void solve() {
    set<int> st;
    int mx = 0;
    int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
    for (int i = la; i <= ra; i ++) {
        for (int j = lb; j <= rb; j ++) {
            mx = max(f(i + j), mx);
            if (mx == 9) {
                cout << mx << '\n';
                return ;
            }
        }
    }
    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}