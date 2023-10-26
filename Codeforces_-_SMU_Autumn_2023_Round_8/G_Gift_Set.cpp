/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-24 22:17:20
 *
 * Problem: G. Gift Set
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481465/problem/G
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
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if(a > b)swap(a, b);
    if(x > y)swap(x, y);
    if(a == b) {
        cout << min(x, y) / a << endl;
        return ;
    }
    // auto check = [&](int mid) {
    //     int xt = x - a * mid;
    //     int yt = y - a * mid;
    //     if(xt < 0 || yt < 0)return false;
    //     xt /= (b - a);
    //     yt /= (b - a);
    //     return (xt + yt) >= mid;
    // };
    // int l = 0, r = 1e9, ans = -1;
    // while(l <= r) {
    //     int mid = l + r >> 1;
    //     if(check(mid))l = mid + 1, ans = mid;
    //     else r = mid - 1;
    // }
    // cout << ans << endl;
    int d1=y-x;
    int d2=b-a;
    
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}