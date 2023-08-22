/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-09 10:52:26
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 200010;
const int M = 1910;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int f[N], g[N];

int  ksm(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res %= MOD;
    return res;
}

int fact(int x) {
    int res = 1;
    for(int i = 1; i <= x; i++) {
        res = (res % MOD * i % MOD) % MOD;
    }
    return res;
}



int C(int n, int m) { //得到C(n,m)的组合数答案
    return (f[n] % MOD * g[m] % MOD * g[n - m] % MOD) % MOD;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    int mx = 0, mxx = -1;
    for(auto &i : a) {
        cin >> i;
        mp[i]++;
        mx = max(mx, i);
    }
    // for(int i = 1; i <= n; i++)cout << g[i] << ' ';
    // cout << endl;
    sort(ALL(a), greater<int>());
    for(int i = 0; i < n; i++) {
        if(mx != a[i]) {
            mxx = a[i];
            break;
        }
    }
    // cout << mx << ' ' << mxx << endl;
    if(mxx == -1 || mp[mx] > 1) {
        cout << fact(n) << endl;
        return ;
    }
    if(mx - mxx >= 2 || mp[mx] > 1) {
        cout << 0 << endl;
        return ;
    }
    int ans = (f[n] % MOD + MOD - f[n - 1] % MOD) % MOD;
    // cout << ans << endl;
    int x = mp[mxx];
    int y = n - x - 1;
    // cout << x << ' ' << y << endl;
    for(int i = 0; i < y; i++) {
        int c = C(y, i);
        int b = f[y - i] % MOD;
        int a = f[x + i] % MOD;
        int sum = ((a * c) % MOD * b % MOD) % MOD;
        // cout << a << ' ' << c << endl;
        ans = (ans + MOD - sum) % MOD;
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD; //计算i的阶乘
        g[i] = g[i - 1] * ksm(i, MOD - 2) % MOD; //计算i的乘法逆元 qpow为快速幂
    }
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}