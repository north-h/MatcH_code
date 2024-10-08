//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
int quickpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}
int n, m;
vector<int> a(100005, 0);
int s1[100005], s2[100005];    //s1[i]定义为,用了i次时的ans
void solve() {
    cin >> n >> m;
    int suma = 0, ansa = 0, sumb = 0, ansb = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], suma += a[i], suma %= mod, ansa += suma, ansa %= mod;
    auto b = a;
    reverse(b.begin() + 1, b.begin() + n + 1);
    for (int i = 1; i <= n; i++) sumb += b[i], sumb %= mod, ansb += sumb, ansb %= mod;
    int q = quickpow(2, mod - 2);
    s1[0] = ansa, s2[0] = ansb;
    for (int i = 1; i <= m; i++) {
        s1[i] = (quickpow(2, i) - 1 + mod) % mod * (n + n * ((quickpow(2, i) - 1 + mod) % mod) % mod) % mod * q % mod * suma % mod + quickpow(2, i) * ansa % mod, s1[i] %= mod;
        s2[i] = (quickpow(2, i) - 1 + mod) % mod * (n + n * ((quickpow(2, i) - 1 + mod) % mod) % mod) % mod * q % mod * sumb % mod + quickpow(2, i) * ansb % mod, s2[i] %= mod;
    }
    int ans = s1[m];
    for (int i = 0; i < m; i++) { //使用i次1操作之后,使用了reverse.
        int sum = suma * quickpow(2, i + 1) % mod;
        int nn = n * quickpow(2, i + 1) % mod;
        int ans0 = (s1[i] + s2[i]) % mod + nn * q % mod * sum % mod * q % mod;
        ans0 %= mod;
        int move = m - i - 1, res = 0;
        res = (quickpow(2, move) - 1 + mod) % mod * (nn + nn * ((quickpow(2, move) - 1 + mod) % mod) % mod) % mod * q % mod * sum % mod + quickpow(2, move) * ans0 % mod, res %= mod;
        ans = max(ans, res);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
//    cin>>t;
    while (t--) solve();
    return 0;
}