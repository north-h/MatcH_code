/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-07 14:25:17 ms
 *
 * Problem: A. Creating Words
 * Contest: Codeforces - Codeforces Round 952 (Div. 4)
 * URL:     https://codeforces.com/contest/1985/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
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
    string a, b; cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << ' ' << b << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}