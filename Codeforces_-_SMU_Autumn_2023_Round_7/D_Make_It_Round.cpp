/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:44
 *
 * Problem: D. Make It Round
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/D
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
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int m2 = 0, m5 = 0;
    int t = n;
    while(t % 2 == 0 && t > 0)m2++, t /= 2;
    t = n;
    while(t % 5 == 0 && t > 0)m5++, t /= 5;
    // debug2(m2, m5);
    int sum = 1;
    while(m5 < m2 && sum * 5 <= m)m5++, sum *= 5;
    while(m2 < m5 && sum * 2 <= m)m2++, sum *= 2;
    // debug1(sum);
    while(sum * 10 <= m)sum *= 10;
    cout << sum *n * (m / sum) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}