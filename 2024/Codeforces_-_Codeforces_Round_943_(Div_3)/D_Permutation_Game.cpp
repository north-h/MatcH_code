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
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<int> p(n + 1), a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    int ss = 0, sb = 0, mxb = 0, mxs = 0, ys = 0, yb = 0;
    for (int i = 1, c = 0; i <= min(k, n); i ++) {
        c += a[pb];
        int x = c + (min(k, n) - i) * a[pb];
        // debug1(x);
        if (a[pb] == mx) yb = c + (k - i) * mx;
        if (sb < x) sb = x, mxb = a[pb];
        pb = p[pb];
    }
    for (int i = 1, c = 0; i <= min(k, n); i ++) {
        c += a[ps];
        int x = c + (min(k, n) - i) * a[ps];
        // debug2(x, c);
        // debug2(a[ps], s);
        if (a[ps] == mx) ys = c + (k - i) * mx;
        if (ss < x) ss = x, mxs = a[ps];
        ps = p[ps];
    }
    // if (mxb == b) lb = 0;
    // if (mxs == s) ls = 0;
    // debug2(lb, ls);
    // debug2(yb, ys);
    // debug2(sb, ss);
    // debug2(mxb, mxs);
    if (k > n) {
        sb += (k - n) * mxb;
        ss += (k - n) * mxs;
    }
    sb = max(sb, yb);
    ss = max(ss, ys);
    // debug2(sb, ss);
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