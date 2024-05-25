/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-25 22:43:13
 *
 * Problem: C. Chamo and Mocha's Array
 * Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1975/problem/C
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
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    auto b = a;
    sort(b.begin() + 1, b.end());
    int ans = b[(n + 1) / 2];
    // debug1(ans);
    for (int i = 1; i < n; i ++) {
        int x = a[i], y = a[i + 1];
        if (x > y) swap(x, y);
        ans = max(ans, x);
    }
    for (int i = 1; i < n - 1; i ++) {
        vector<int> t  = {a[i], a[i + 1], a[i + 2]};
        sort(t.begin(), t.end());
        ans = max(ans, t[1]);
    }
    cout << ans << '\n';
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