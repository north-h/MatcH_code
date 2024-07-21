// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 1000010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

struct comb2 {
    vector<int> fac, inf;

    comb2(int n) {
        fac.resize(n + 1);
        inf.resize(n + 1);
        fac[0] = inf[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
        }
    }

    int ksm(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int query(int n, int m) {
        int ans;
        ans = fac[n] * inf[n - m] % mod * inf[m] % mod;
        return ans;
    }

};

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int c1 = 0, c2 = 0, cv = 0;
    for (auto i : s) {
        c1 += (i == '(');
        c2 += (i == ')');
        cv += (i == '?');
    }
    comb2 c(n + 1);
    if (c1 > n / 2 || c2 > n / 2 || n & 1) {
        cout << 0 << '\n';
    } else cout << c.query(cv, abs(c1 - c2) + (cv - abs(c1 - c2)) / 2) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}