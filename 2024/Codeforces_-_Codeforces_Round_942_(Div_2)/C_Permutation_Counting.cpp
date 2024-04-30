/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-30 22:48:26
 *
 * Problem: C. Permutation Counting
 * Contest: Codeforces - Codeforces Round 942 (Div. 2)
 * URL:     https://codeforces.com/contest/1972/problem/C
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[1] + k << '\n';
        return ;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++) cout << s[i] << " \n"[i == n];
    auto check = [&](int l, int r)-> bool {
        // debug2(l, r);
        ll x = (ll)(r - l + 1) * a[r] - (s[r] - s[l - 1]);
        // debug2((r - l + 1) * a[r], s[r] - s[l - 1]);
        // debug2(x, k);
        return x <= k;
    };
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = n, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(i, mid)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        debug2(i, res);
        // debug1(a[res] + k);
        ll x = a[res], an;
        debug1(x);
        if (res == i) {
            x += k;
            an = x + (n - i) * (x - 1) + (n - res);
            ans = max(ans, an);
        } else if (res != -1) {
            ll y = (ll)(res - i + 1) * a[res] - (s[res] - s[i - 1]);
            // debug2(k, y);
            x += (k - y) / n;
            an = x + (n - i) * (x - 1) + (n - res);
            ans = max(ans, an);
        }
        debug1(an);
        debug1(x);
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