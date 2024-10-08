#include <bits/stdc++.h>
const int N = 200010;
const int mod = 1e9 + 7;
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