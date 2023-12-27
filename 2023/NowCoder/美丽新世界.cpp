/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-25 11:19:10
 *
 * Problem: 美丽新世界
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/70307/A
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


int ksm(int a, int b, int p) {
    int res = 1;
    while(b) {
        if(b & 1)res *= a, res %= p;
        b >>= 1;
        a = a * a;
        a %= p;
    }
    return res;
}

void solve() {
    int f1, f2, p, A, n, fx;
    cin >> f1 >> f2 >> p >> A >> n;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            cout << f1 << ' ';
            continue;
        }
        if(i == 2) {
            cout << f2 << ' ';
            continue;
        }
        fx = (int)log2(ksm(f2, f1, p) % p + 1) + A;
        cout << fx << ' ';
        f1 = f2;
        f2 = fx;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}