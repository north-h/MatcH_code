/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-25 16:30:38
 *
 * Problem: G. Broken Clock
 * Contest: Codeforces - 重庆市赛复活赛
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/488622/problem/G
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
#define ll long long
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
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    char a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if(d >= '6')d = '0';
    int x = (a - '0') * 10 + (b - '0');
    int y = (d - '0') * 10 + (e - '0');
    // debug2(x, y);
    if(n == 12) {
        if(x == 0)a = '1';
        else if(x > 12) {
            if(b != '0')a = '0';
            else a = '1';
        }
    }
    if(n == 24) {
        if(x >= 24)a = '0';
    }
    cout << a << b << c << d << e << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}