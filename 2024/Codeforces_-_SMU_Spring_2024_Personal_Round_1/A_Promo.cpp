/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:28 ms
 *
 * Problem: A. Promo
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
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
    int n, m; cin >> n >> m;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    sort(s.begin() + 1, s.end());
    for (int i = 1; i <= n; i ++) {
        s[i] += s[i - 1];
    }
    while (m --) {
        int x, y; cin >> x >> y;
        int l = n - x + 1;
        int r = l + y - 1;
        cout << s[r] - s[l - 1] << '\n';
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}