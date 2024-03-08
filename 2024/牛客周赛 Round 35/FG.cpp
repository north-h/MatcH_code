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
//  #define LOCAL
// const int N = 10010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

struct comb2{
    vector<int> fac,inf;

    comb2(int n) {
        fac.resize(n + 1);
        inf.resize(n + 1);
        fac[0] = inf[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = fac[i - 1] * i % mod;
            inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
        }
    }

    int ksm(int a, int b){    // 快速幂
        int res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
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
    int n;
    cin >> n;
    comb2 C(n + 1);
    vector<int> num(n + 1), v(4);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> num[i];
        v[num[i]] ++;
    }
    for (int i = 0; i <= v[2]; i ++) {
        a += C.query(v[2], i) * (i + 1) % mod;
        a %= mod;
    }
    for (int i = 0; i <= v[3]; i ++) {
        b += C.query(v[3], i) * (i + 1) % mod;
        b %= mod;
    }
    cout << (a * b % mod * C.ksm(2, v[1]) % mod - 1 + mod) % mod << endl;
    // cout << 1 << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}