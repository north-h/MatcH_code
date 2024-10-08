/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-07 15:25:13
 *
 * Problem: M. 810975
 * Contest: Codeforces - SMU Autumn 2024 Team Round 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/555870/problem/M
 * MemoryL: 256 MB
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
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * ksm(i, mod - 2) % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int calc(int n, int m, int k) {
    int res = 0;
    for (int i = 1; i * k <= m && i <= n - m + 1; i ++) {
        if (i & 1) {
            res = (res + C(n - m + 1, i) * (C(n - i * k, n - m)) % mod) % mod;
        } else {
            res = (res - C(n - m + 1, i) * (C(n - i * k, n - m)) % mod + mod) % mod;
        }
    }
    return res;
}


void solve() {
    init();
    int n, m, k; cin >> n >> m >> k;
    cout << (calc(n, m, k) - calc(n, m, k + 1) + mod) % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}