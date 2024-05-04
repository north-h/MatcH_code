/*
 * ==========================================================
 * Author:  north_h
 * Time:    2024-05-04 20:14:54 ms
 *
 * Problem: E - Clique Connect
 * Contest: AtCoder - AtCoder Beginner Contest 352
 * URL:     https://atcoder.jp/contests/abc352/tasks/abc352_e
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==========================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
#define int long long

using namespace std;
// using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 1; i <= m; i ++) {
        int k, c; cin >> k >> c;
        for (int j = 1; j <= k; j ++) {
            int x; cin >> x;
            mp[c].push_back(x);
        }
    }
    set<int> st, T;
    for (int i = 1; i <= n; i ++) st.insert(i);
    int ans = 0;
    bool ok = false;
    for (auto [x, y] : mp) {
        for (auto j : y) {
            if (st.size() && st.count(j)) {
                st.erase(j);
                T.insert(j);
                if (ok) ans += x;
                else ok = true;
            }
            if (!st.size()) {
                cout << ans << '\n';
                return ;
            }
        }
    }
    cout << -1  << '\n';
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