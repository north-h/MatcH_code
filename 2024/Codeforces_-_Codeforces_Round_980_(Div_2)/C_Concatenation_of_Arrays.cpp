/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-21 22:09:02
 *
 * Problem: C. Concatenation of Arrays
 * Contest: Codeforces - Codeforces Round 980 (Div. 2)
 * URL:     https://codeforces.com/contest/2024/problem/C
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
    int n; cin >> n;
    vector<array<int, 2>> a;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [&](array<int, 2> x, array<int, 2> y) {
        int xx = min(x[0], x[1]), yy = min(y[0], y[1]);
        if (xx == yy) return max(x[0], x[1]) < max(y[0], y[1]);
        return min(x[0], x[1]) < min(y[0], y[1]);
    });
    for (auto [x, y] : a) cout << x << ' ' << y << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}