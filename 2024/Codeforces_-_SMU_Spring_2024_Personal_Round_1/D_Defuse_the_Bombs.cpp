/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:41 ms
 *
 * Problem: D. Defuse the Bombs
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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

void solve(int t) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    auto check = [&](ll x) -> bool {
        ll cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] < x) cnt += x - a[i];
        }
        return cnt <= x;
    };
    ll l = 0, r = 2e9, ans;
    while (l <= r) {
        ll mid = l + r >> 1;
        // debug2(l, r);
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << "Case #" << t << ": " << ans + 1 << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1, t = 1;
    cin >> h_h;
    while (h_h--)solve(t ++);
    return 0;
}