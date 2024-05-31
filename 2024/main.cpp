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

ll ksm(int a, int b) {
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
    ll ans = 0;
    int ok = 0;
    m -= cnt[0];
    for (int i = 1; i < 10; i ++) {
        ll x = 0;
        if (!cnt[i]) continue;
        if (ok == 1) {
            m -= cnt[0];
            x = (ksm(10, cnt[0]) - 1 + mod) % mod * ksm(9, mod - 2) % mod * ksm(10, n - cnt[0]);
            ans = (ans + x) % mod;
            ok ++;
            continue;
        }
        if (m >= cnt[i]) {
            m -= cnt[i];
            x = (ksm(10, cnt[i]) - 1 + mod) % mod * ksm(9, mod - 2) % mod * ksm(10, n - cnt[i]);
            ans = (ans + x) % mod;
            ok ++;
        } else {
            x = (ksm(10, m) - 1 + mod) % mod * ksm(9, mod - 2) % mod * ksm(10, n - m);
            ans = (ans + mod) % mod;
            ok ++;
            m = 0;
        }
        debug1(ans);
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

