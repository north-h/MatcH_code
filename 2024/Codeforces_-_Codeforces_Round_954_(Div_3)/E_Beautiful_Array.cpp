/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 13:20:38 ms
 *
 * Problem: E. Beautiful Array
 * Contest: Codeforces - Codeforces Round 954 (Div. 3)
 * URL:     https://codeforces.com/contest/1986/problem/E
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> mp;
    map<int, int> pp;
    for (auto & i : a) {
        cin >> i;
        pp[i] ++;
        pp[i] %= 2;
    }
    vector<int> vis(n);
    ll ans = 0;
    set<int> st;
    for (auto [x, y] : pp) {
        if (y == 1) {
            st.insert(x);
            mp[x % k].push_back(x);
        }
    }
    for (auto i : st) cout << i << ' ';
    cout << '\n';
    for (auto [x, y] : mp) {
        cout << x << ":";
        for (auto j : y) cout << j << ' ';
        cout << '\n';
    }
    int cnt = 0;
    for (auto [x, y] : mp) {
        if (y.size() & 1 && y.size() > 1) {
            cnt ++;
        }
    }
    if (cnt >= 2) {
        cout << -1 << '\n';
        return ;
    }
    for (auto [x, y] : mp) {
        sort(y.begin(), y.end());
        // for (auto i : y) cout << i << ' ';
        // cout << '\n';
        ll res = 0;
        for (int i = 1; i < y.size(); i += 2) res += (y[i] - y[i - 1]);
        if (y.size() & 1 && y.size() > 1) {
            int t = 0;
            for (int i = 1; i < )
        }
        ans += res / k;
        // debug2(res, ans);
    }
    if (cnt == 2) cout << -1 << '\n';
    else cout << ans << '\n';
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

// 0:3 9 18 30
// 1:1 4 10 22 28
// 2:2 14 17 20