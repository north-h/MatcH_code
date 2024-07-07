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

ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int m = n;
    vector<int> cnt(10);
    for (int i = 0; i < 10; i ++) {
        int x; cin >> x;
        cnt[i] = x;
    }
    if (n == 1) {
        for (int i = 0; i < 10; i ++) {
            if (cnt[i]) {
                cout << i << '\n';
                return ;
            }
        }
    }
    int mn = 10;
    for (int i = 1; i < 10; i ++) {
        if (cnt[i]) mn = min(mn, i);
    }
    ll ans = mn * ksm(10, n - 1) % mod, x;
    cnt[mn] --;
    m --;
    if (m >= cnt[0]) {
        m -= cnt[0];
        cnt[0] = 0;
    } else m = 0;
    for (int i = 1; i < 10 && m; i ++) {
        if (m >= cnt[i]) {
            x = (ksm(10, cnt[i]) - 1 + mod) % mod * ksm(9, mod - 2) % mod * i % mod * ksm(10, m - cnt[i]) % mod ;
            ans = (ans + x) % mod;
            m -= cnt[i];
        }
        else {
            x = (ksm(10, m) - 1 + mod) % mod * ksm(9, mod - 2) % mod * i % mod;
            ans = (ans + x) % mod;
            break;
        }
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

