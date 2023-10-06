/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-06 13:43:12
 *
 * Problem: 覆叶之交
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/66651/C
 * MemoryL: 524288 MB
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
const int N = 1000000000;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}
inline void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    pair<int, int> l1, r1, l2, r2, l3, r3;
    cin >> l1.fi >> l1.se >> r1.fi >> r1.se >> l2.fi >> l2.se >> r2.fi >> r2.se >> l3.fi >> l3.se >> r3.fi >> r3.se;
    int ans = 0;
    ans += abs(l2.fi - r2.fi) * abs(l2.se - r2.se);
    ans += abs(l1.fi - r1.fi) * abs(l1.se - r1.se);
    ans += abs(l3.fi - r3.fi) * abs(l3.se - r3.se);
    // debug1(ans);
    int x1 = max(l1.fi, l2.fi), y1 = max(l1.se, l2.se);
    int x2 = min(r1.fi, r2.fi), y2 = min(r1.se, r2.se);
    // debug2(x1, y1);
    // debug2(x2, y2);
    if(x2 >= x1 && y2 >= y1)ans -= abs(x2 - x1) * abs(y2 - y1);
    int x3 = max(l1.fi, l3.fi), y3 = max(l1.se, l3.se);
    int x4 = min(r1.fi, r3.fi), y4 = min(r1.se, r3.se);
    if(x4 >= x3 && y4 >= y3)ans -= abs(x4 - x3) * abs(y4 - y3);
    // debug1(ans);
    int x5 = max(l2.fi, l3.fi), y5 = max(l2.se, l3.se);
    int x6 = min(r2.fi, r3.fi), y6 = min(r2.se, r3.se);
    if(x6 >= x5 && y6 >= y5)ans -= abs(x6 - x5) * abs(y6 - y5);
    // debug1(ans);
    int x = max({l1.fi, l3.fi, l2.fi}), y = max({l1.se, l3.se, l2.se});
    int xx = min({r1.fi, r3.fi, r2.fi}), yy = min({r1.se, r3.se, r2.se});
    if(xx >= x && yy >= y)ans +=  abs(xx - x) * abs(yy - y);
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}