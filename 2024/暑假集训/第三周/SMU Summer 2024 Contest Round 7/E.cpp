// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

int ksm(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return res;
}

int C(int a, int b) {
    int ans = 1, inv = 1;
    for (int i = 1; i <= b; i ++) {
        inv = inv * ksm(i, mod - 2) % mod;
    }
    for (int i = a - b + 1; i <= a; i ++) {
        ans = ans * i % mod;
    }
    return ans * inv % mod;
}

void solve() {
    int a, b, n; cin >> n >> a >> b;
    cout << (((ksm(2, n) - C(n, a) + mod) % mod - C(n, b) + mod) % mod - 1 + mod) % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}