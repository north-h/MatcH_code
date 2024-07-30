/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-30 22:37:35
 *
 * Problem: C. Even Positions
 * Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1997/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
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
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;
    for (auto &i : s) {
        if (i == '(') l ++;
        else if (i == '_') {
            if (l <= r) i = '(', l ++;
            else i = ')', r ++;
        } else r ++;
        // debug2(l, r);
    }
    // cout << s << '\n';
    vector<int> L;
    int ans = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '(') {
            L.push_back(i);
        } else {
            ans += (i - L.back());
            L.pop_back();
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}