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
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ss = 0, sb = 0, c = 0;
    bool fs = 1, fb = 1;
    while (true) {
        if (c % 2 == 0) {
            sb += a[pb];
            if (fb && a[p[pb]] > a[pb] && ps != p[pb]) pb = p[pb];
            else fb = 0;
        } else {
            ss += a[ps];
            if (fs && a[p[ps]] > a[ps] && pb != p[ps]) ps = p[ps];
            else fs = 0;
        }
        c ++;
        k --;
        if (!fb && !fs) {
            sb += (k + 1) / 2 * a[pb];
            ss += k / 2 * a[ps];
            break;
        }
    }
    debug2(pb, ps);
    debug2(sb, ss);
    if (ss == sb) cout << "Draw" << '\n';
    else if (sb > ss) cout << "Body" << '\n';
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