/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-20 20:27:02 ms
 *
 * Problem: B - Dentist Aoki
 * Contest: AtCoder - AtCoder Beginner Contest 350
 * URL:     https://atcoder.jp/contests/abc350/tasks/abc350_b
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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        mp[i] = 1;
    }
    for (int i = 1; i <= m; i ++) {
        int x;
        cin >> x;
        if (mp[x] == 0) n ++;
        else n --;
        mp[x] ^= 1;
    }
    cout << n << '\n';
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