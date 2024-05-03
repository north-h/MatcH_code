/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-03 01:04:23
 *
 * Problem: D. Permutation Game
 * Contest: Codeforces - Codeforces Round 943 (Div. 3)
 * URL:     https://codeforces.com/contest/1968/problem/D
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
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<int> p(n + 1), a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) cin >> a[i];
    ll ss = 0, sb = 0, c = 0;
    for (int i = 1; i <= min(k, n); i ++) {
        ll x = c + (ll)(k - i + 1) * a[pb];
        sb = max(sb, x);
        c += a[pb];
        pb = p[pb];
    }
    c = 0;
    for (int i = 1; i <= min(k, n); i ++) {
        ll x = c + (ll)(k - i + 1) * a[ps];
        ss = max(ss, x);
        c += a[ps];
        ps = p[ps];
    }
    if (ss == sb) cout << "Draw" << '\n';
    else if (sb > ss) cout << "Bodya" << '\n';
    else cout << "Sasha" << '\n';
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