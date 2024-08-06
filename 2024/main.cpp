// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define ll long long
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

ll n;
inline bool check(ll x, ll m, ll k, ll h) {
    ll res = 0;
    while (x >= m) {
        res += x / m * m;
        x = x % m + x / m * k;
        if (res >= h) return 1;
    }
    res += x;
    return res >= h;
}

void solve() {
    ll m, k, h;
    cin >> m >> k >> h;
    if (!h) {cout << "0\n"; return ;}
    if (k == m) {cout << min(h, m) << "\n"; return ;}
    ll ans = h - h / m * k;
    for (ll i = ans; i <= ans + 10; i++)
        if (check(i, m, k, h)) {cout << i << "\n"; return ;}
    ans += 11;
    ll l = ans, r = h;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid, m, k, h)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
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