/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-21 23:18:04
 *
 * Problem: D. Robert Hood and Mrs Hood
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<array<int, 2>> a(k + 1);
    vector<int> s(n + 2);
    map<int, int> st, ed;
    for (int i = 1; i <= k; i ++) {
        cin >> a[i][0] >> a[i][1];
        st[a[i][0]] ++;
        ed[a[i][1]] ++;
    }
    int m = INF, b = 0;
    int mm, bb;
    int ans = 0;
    for (int i = 1, j = 1; i <= n; i ++) {
        ans += st[i];
        if (i < d) continue;
        if (i > d) ans -= ed[j ++];
        if (m > ans) m = ans, mm = j;
        if (b < ans) b = ans, bb = j;
    }
    cout << bb << ' ' << mm << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}