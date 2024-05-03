/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-02 22:37:13
 *
 * Problem:  Divisibility by 2^n
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-1744D#author=GPT_zh
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
    int c = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        while (x % 2 == 0) c ++, x /= 2;
    }
    // debug1(c);
    // if (c >= n) {
    //     cout << 0 << '\n';
    //     return ;
    // }
    c  = n - c;
    vector<int > b;
    int ans = 0;
    for (int i = n; i >= 1; i --) {
        int v = 0, x = i;
        while (x % 2 == 0) v ++, x /= 2;
        if (v == 0) continue;
        b.push_back(v);
    }
    sort(b.rbegin(), b.rend());
    for (auto i : b) {
        if (c <= 0) break;
        c -= i;
        ans ++;
    }
    if (c <= 0) cout << ans << '\n';
    else cout << -1 << '\n';
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