/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-15 13:02:20
 *
 * Problem: B. Shovels and Swords
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479563/problem/B
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
    int a, b;
    cin >> a >> b;
    cout << min((a + b) / 3, min(a, b)) << endl;
    //     if(a < b)swap(a, b);
    //     if(a == 0 || b == 0) {
    //         cout << 0 << endl;
    //         return ;
    //     }
    //     if(a == b) {
    //         int x = a / 3;
    //         int y = a % 3;
    //         cout << x * 2 + (y >= 2) << endl;
    //         return ;
    //     }
    //     int l = 0, r = b / 3, res = 0;
    //     // debug2(l, r);
    //     while(l <= r) {
    //         int mid = l + r >> 1;
    //         int x = a - mid * 3;
    //         int y = b - mid * 3;
    //         // debug1(x * 1.0 / y);
    //         if((x * 1.0 / y) >= 2)r = mid - 1, res = mid;
    //         else l = mid + 1;
    //     }
    //     // debug1(res);
    //     int x = a - res * 3;
    //     int y = b - res * 3;
    //     int ans = res * 2 + min(x / 2, y);
    //     if(res >= 1) {
    //         x = a - (res - 1) * 3;
    //         y = b - (res - 1) * 3;
    //         ans = max(ans, (res - 1) * 2 + min(x / 2, y));
    //     }
    //     if(res >= 2) {
    //         x = a - (res - 2) * 3;
    //         y = b - (res - 2) * 3;
    //         ans = max(ans, (res - 2) * 2 + min(x / 2, y));
    //     }
    //     if(res <= b / 3) {
    //         x = a - (res + 1) * 3;
    //         y = b - (res + 1) * 3;
    //         ans = max(ans, (res + 1) * 2 + min(x / 2, y));
    //     }
    //     if(res <= b / 3) {
    //         x = a - (res + 2) * 3;
    //         y = b - (res + 2) * 3;
    //         ans = max(ans, (res + 2) * 2 + min(x / 2, y));
    //     }
    //     cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}