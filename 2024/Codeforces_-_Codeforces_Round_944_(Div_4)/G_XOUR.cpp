/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-11 13:31:52
 *
 * Problem: G. XOUR
 * Contest: Codeforces - Codeforces Round 944 (Div. 4)
 * URL:     https://codeforces.com/contest/1971/problem/G
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
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i] / 4].push_back(i);
    }
    vector<int> ans(n + 1);
    for (auto &[x, y] : mp) {
        vector<int> t;
        for (auto i : y) t.push_back(a[i]);
        sort(t.begin(), t.end());
        sort(y.begin(), y.end());
        // debug1(x);
        for (int i = 0; i < t.size(); i ++) {
            ans[y[i]] = t[i];
        }
    }
    for (int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];
}

//0 1 2 3
//4 5 6 7
//8 9 10 11

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