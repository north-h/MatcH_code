/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-03 01:04:31
 *
 * Problem: F. Equal XOR Segments
 * Contest: Codeforces - Codeforces Round 943 (Div. 3)
 * URL:     https://codeforces.com/contest/1968/problem/F
 * MemoryL: 256 MB
 * TimeL:   5000 ms
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
    int n, m; cin >> n >> m;
    vector<int> s(n + 1);
    map<int, set<int>> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] ^= s[i - 1];
        mp[s[i]].insert(i);
    }
    while (m --) {
        int l, r; cin >> l >> r;
    }
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