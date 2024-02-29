// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

int ksm(int x, int y) {
    int res = 1;
    while (y) {
        if(y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

int f[N], inf[N];

int C(int n, int m) {
    return f[n] * inf[m] % mod * inf[n - m] % mod;
}

void solve() {
    f[0] = 1;
    inf[0] = 1;
    for (int i = 1; i < N; i ++) {
        f[i] = f[i - 1] * i % mod;
        inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
    }
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int k = 0; k <= m; k ++) {
        if (k % 2 == 0) {
            ans = (ans + C(m, k) * ksm(m - k, n) % mod) % mod;
        } else {
            ans = (ans - C(m, k) * ksm(m - k, n) % mod + mod) % mod;
        }
    }
    cout << ans * inf[m] % mod << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}