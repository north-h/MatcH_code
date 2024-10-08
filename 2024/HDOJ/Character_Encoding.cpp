/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-07 14:52:17
 *
 * Problem: Character Encoding
 * Contest: HDOJ
 * URL:     https://acm.hdu.edu.cn/showproblem.php?pid=6397
 * MemoryL: 131 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, mod = 998244353;

using namespace std;

int fac[N], inv[N];

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * ksm(i, mod - 2) % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    init();
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i * n <= k; i ++) {
        if (i & 1) {
            ans = (ans - C(m, i) * C(k + m - 1 - i * n, m - 1) % mod + mod) % mod;
        } else {
            ans = (ans + C(m, i) * C(k + m - 1 - i * n, m - 1) % mod) % mod;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}