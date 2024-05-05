// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;
using ll = long long;

ll ksm(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<ll> dp (100010);
    dp[0] = 3, dp[1] = 5;
    for (int i = 2; i < 100010; i ++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    ll ans = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '1') ans = (ans + dp[i]) % mod;
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
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}