// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

int get(int s) {
    s ++;
    int sum = 0, zq = 2, gs = 1, zqs = 1;
    for (int j = 0; j < 61; j ++) {
        int x = s / zq, y = s % zq;
        sum += x * zqs % mod;
        sum %= mod;
        sum += max((y - gs), 0ll);
        sum %= mod;
        gs *= 2;
        zq *= 2;
        zqs *= 2;
    }
    return sum;
}

void solve() {
    int t; cin >> t;
    while (t --) {
        int l, r; cin >> l >> r;
        cout << (get(r) - get(l - 1) + mod) % mod << '\n';

    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}