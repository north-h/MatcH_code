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
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if ((ll)mid * a[mid] - s[mid] <= k) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    ll x = a[res];
    ll y = (ll)res * a[res] - s[res];
    x += (k - y) / res;
    ans = x + (n - 1) * (x - 1) + (n - res) + (k - y) % res;
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