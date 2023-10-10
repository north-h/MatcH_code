/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-10 01:14:30
 *
 * Problem: B. Fear of the Dark
 * Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1886/problem/B
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
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double ans = 1e9;
    double res1 = sqrt(abs(ax) * abs(ax) + abs(ay) * abs(ay));
    double res2 = sqrt(abs(bx) * abs(bx) + abs(by) * abs(by));
    double ans1 = sqrt(abs(ax - px) * abs(ax - px) + abs(ay - py) * abs(ay - py));
    double ans2 = sqrt(abs(bx - px) * abs(bx - px) + abs(by - py) * abs(by - py));
    ans = sqrt(abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by)) / 2;
    debug1(ans);
    if(ans < res1 && ans < res2)ans = 1e9;
    if(ans < ans1 && ans < ans2)ans = 1e9;
    // debug2(ax, ay);
    // debug2(ax, ay);
    double r1 = max(ans1, res1);
    double r2 = max(ans2, res2);
    debug2(res1, res2);
    debug2(r1, r2);
    ans = min(min(r1, r2), ans);
    cout << lf(10) << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}