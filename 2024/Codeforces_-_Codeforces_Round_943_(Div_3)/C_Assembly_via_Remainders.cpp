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
    vector<int> a(n + 1);
    for (int i = 1; i < n; i ++) cin >> a[i];
    int lst = a[1] + 1;
    cout << lst << ' ';
    for (int i = 1; i < n; i ++) {
        if (i == n - 1) lst += a[i];
        else {
            if (a[i] > a[i + 1]) lst = a[i];
            else lst = (a[i + 1] + lst - 1) / lst * lst + a[i];
        }
        cout << lst << ' ';
    }
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