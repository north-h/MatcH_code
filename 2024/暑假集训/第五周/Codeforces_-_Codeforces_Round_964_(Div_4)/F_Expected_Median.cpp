/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:46
 *
 * Problem: F. Expected Median
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/F
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 200010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

int fac[N], inf[N];

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
    fac[0] = inf[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
    }
}

int C(int n, int m) {
    return fac[n] * inf[m] % mod * inf[n - m] % mod;
}


void solve() {
    int n, k; cin >> n >> k;
    int c0 = 0, c1 = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (x == 0) c0 ++;
        else c1 ++;
    }
    int zw = (k + 1) / 2;
    if (c1 < zw) {
        cout << 0 << '\n';
        return ;
    }
    int ans = 0;
    for (int i = zw; i <= c1 && i <= k; i ++) {
        if (c0 >= k - i) ans = (ans + C(c1, i) * C(c0, k - i) % mod) % mod;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    init();
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}