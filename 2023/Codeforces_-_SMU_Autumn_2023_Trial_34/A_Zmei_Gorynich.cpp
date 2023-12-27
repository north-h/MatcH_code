/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-12 18:33:01
 *
 * Problem: A. Zmei Gorynich
 * Contest: Codeforces - SMU Autumn 2023 Trial 34
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484051/problem/A
 * MemoryL: 256 MB
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int  n, m;
    cin >> n >> m;
    // debug2(n, m);
    int mx = 0;
    int m1 = 0;
    for(int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        mx = max(mx, x);
        m1 = max(m1, x - y);
    }
    m = max(m - mx, 0ll);
    // debug2(m1, mx);
    // debug2(n, m1);
    if(m == 0)cout << 1 << endl;
    else if(m1 <= 0)cout << -1 << endl;
    else cout << (m + m1 - 1) / m1 + 1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}