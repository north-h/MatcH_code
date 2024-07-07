/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 13:14:15 ms
 *
 * Problem: C. Update Queries
 * Contest: Codeforces - Codeforces Round 954 (Div. 3)
 * URL:     https://codeforces.com/contest/1986/problem/C
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
    vector<int> ind(m);
    string s, c;
    cin >> s;
    set<int> st;
    for (int i = 0; i < m; i ++) {
        cin >> ind[i];
    }
    sort(ind.begin(), ind.end());
    unique(ind.begin(), ind.end());
    cin >> c;
    sort(c.rbegin(), c.rend());
    reverse(ind.begin(), ind.end());
    for (int i = 0; i < m; i ++) {
        s[ind[i] - 1] = c[i];
    }
    cout << s << '\n';
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