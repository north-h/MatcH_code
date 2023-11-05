/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-05 12:52:50
 *
 * Problem: C. 方格染色
 * Contest: Codeforces - The 10th Jimei University Programming Contest
 * URL:     https://codeforces.com/gym/104741/problem/C
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

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
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 100010;
const int M = 1910;
const int mod = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


int fac[N], inv[N];

int power(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1)ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
void init() {
    fac[0] = 1;
    inv[0] = power(1, mod - 2);
    for(int i = 1; i < N; i++) {
        fac[i] = i * fac[i - 1] % mod;
        inv[i] = power(fac[i], mod - 2);
    }
}
int C(int x, int y) {
    if(x < y)return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(k > n)cout << 0 << endl;
    else if(k == 0)cout << 1 << endl;
    else {
        for(int i = 0; i < k; i++) {
            int res = C(k - 1, i) % mod;
            res = res * power(2, i + 1);
            res %= mod;
            res = res * C(n - k + 1, i + 1) % mod;
            ans = (ans + res) % mod;
        }
        cout << ans % mod << endl;
    }
}

int32_t main() {
    init();
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}