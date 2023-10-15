/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-15 13:03:12
 *
 * Problem: F. Fair Division
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479563/problem/F
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
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int v1 = 0, v2 = 0;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        if(x == 1)v1++;
        else v2++;
    }
    int x = v1 / 2;//0 1 2 3
    int y = v2 % 2;//0 1
    if(y == 1 && x == 0 || v1 & 1)cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}