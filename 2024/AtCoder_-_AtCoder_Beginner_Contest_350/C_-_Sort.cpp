/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-20 20:27:06 ms
 *
 * Problem: C - Sort
 * Contest: AtCoder - AtCoder Beginner Contest 350
 * URL:     https://atcoder.jp/contests/abc350/tasks/abc350_c
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
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
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n + 1);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        a[i] = x;
        mp[x] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i ++) {
        if (i == a[i]) continue;
        int p = mp[i];
        ans.push_back({i, p});
        mp[i] = i;
        mp[a[i]] = p;
        swap(a[i], a[p]);
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
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