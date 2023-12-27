/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-27 00:11:37
 *
 * Problem: B. Laura and Operations
 * Contest: Codeforces - Codeforces Round 911 (Div. 2)
 * URL:     https://codeforces.com/contest/1900/problem/B
 * MemoryL: 256 MB
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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max({a, b, c});
    int ana = 0, anb = 0, anc = 0;
    int aa = b + c;
    int bb = a + c;
    int cc = a + b;
    if(a == mx) {
        if(abs((a - b) - aa) % 2 == 0)anb = 1;
        if(abs((a - c) - aa) % 2 == 0)anc = 1;
        // if(b == c)ana = 1;
        a %= min(b, c);
        if((abs(b - c) - (a + c)) % 2 == 0)ana = 1;
    } else if(b == mx) {
        if(abs((b - a) - bb) % 2 == 0)ana = 1;
        if(abs((b - c) - bb) % 2 == 0)anc = 1;
        // if(a == c)anb = 1;
        b %= min(a, c);
        if((abs(a - b) - (b + c)) % 2 == 0)anb = 1;
    } else {
        if(abs((c - a) - cc) % 2 == 0)ana = 1;
        if(abs((c - b) - cc) % 2 == 0)anb = 1;
        // if(b == a)anc = 1;
        c %= min(b, c);
        if((abs(c - b) - (a + b)) % 2 == 0)anc = 1;
    }
    cout << ana << ' ' << anb << ' ' << anc << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}