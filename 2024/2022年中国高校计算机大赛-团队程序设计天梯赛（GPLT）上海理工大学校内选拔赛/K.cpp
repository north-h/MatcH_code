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
const int N = 10010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int inv(int x) {
    return ksm(x, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    int ans = ((n % mod) * (n % mod)) % mod;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        int k = n / l;
        ans = (ans - k % mod * (l + r) % mod * ((r - l + 1 + mod) % mod) % mod * inv(2) % mod + mod) % mod;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}