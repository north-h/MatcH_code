// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int fac[N], inf[N];
int mod, n;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m) {
    return fac[n] * inf[n - m] % mod * inf[m] % mod;
}

void solve() {
    cin >> n >> mod;
    fac[0] = inf[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
    }
    cout << 3 * n - 2 << ' ';
    for (int i = 2; i < n; i ++) {
        debug1(C(3 * n - 2, i));
        int ans = (C(3 * n - 2, i) - (n - 1) - 4 + mod) % mod;
        cout << ans << ' ';
    }
    // cout << C(46, 2) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}