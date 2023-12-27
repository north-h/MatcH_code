/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-27 12:55:59
 *
 * Problem: F. 新取模运算
 * Contest: Codeforces - Huazhong University of Science of Technology Freshmen Cup 2023
 * URL:     https://codeforces.com/gym/104728/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1000010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, p;
int fact[N];

int ksm(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

int cal(int n) {
    if(n < p)return fact[n];
    return ksm(fact[p - 1], n / p) % p * fact[n % p] % p * cal(n / p) % p;
}

void solve() {
    cin >> n;
    cout << cal(n) % p << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h >> p;
    fact[0] = fact[1] = 1;
    for(int i = 2; i < p; i++) {
        fact[i] = (i * fact[i - 1]) % p;
    }
    while (h_h--)solve();
    return 0;
}