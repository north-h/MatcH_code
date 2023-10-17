/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-14 14:01:49
 *
 * Problem: C. Magic Ship
 * Contest: Codeforces - SMU Autumn 2023 Trial 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478090/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    string s;
    cin>>s;
    int n=s.size();
    vector<int> u(n+1),d(n+1),l(n+1),r(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='U')u[i+1]=1;
        else if(s[i]=='D')d[i+1]=1;
        else if(s[i]=='L')l[i+1]=1;
        else r[i+1]=1;
    }
    for(int i=1;i<n;i++){
        u[i]+=u[i-1];
        d[i]+=d[i-1];
        l[i]+=l[i-1];
        r[i]+=r[i-1];
    }
    
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}