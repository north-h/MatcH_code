/*
 * =======================================================================
 * Author:  north_h
 * Time:    2023-09-29 10:37:12
 *
 * Problem: B. Gabriel and Caterpillar
 * Contest: Codeforces - SMU Autumn 2023 Trial 3
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475546/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ========================================================================
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
const double PI = 3.1415926;
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;
    if(h2 - h1 <= a * 8)cout << 0 << endl;
    else if(a <= b)cout << -1 << endl;
    else {
        int res = h1 + (8 * a - 12 * b);
        // cout << res << endl;
        int x = a * 12;
        int y = b * 12;
        int ans = h2 - res - x;
        cout << (ans + x - y - 1) / (x - y) + 1 << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}