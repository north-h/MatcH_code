/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-03 01:04:19
 *
 * Problem: C. Assembly via Remainders
 * Contest: Codeforces - Codeforces Round 943 (Div. 3)
 * URL:     https://codeforces.com/contest/1968/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> x(n + 1);
    int lst = 501;
    cout << lst << ' ';
    for (int i = 1; i < n; i ++) {
        cin >> x[i];
        lst += x[i];
        cout << lst << ' ';
    }
    // int lst = x[1] + 1;
    // cout << lst << ' ';
    // for (int i = 1; i < n; i ++) {
    //     if (i == n - 1) lst += x[i];
    //     else {
    //         if (x[i] > x[i + 1]) lst = x[i];
    //         else lst = (x[i + 1] + lst - 1) / lst * lst + x[i];
    //     }
    //     cout << lst << ' ';
    // }
    cout << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}