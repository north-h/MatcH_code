/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-26 16:04:05
 *
 * Problem: 松鼠搬粮仓
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69246/O
 * MemoryL: 524288 MB
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

int dpmax[M][M], dpmin[M][M];
int s[ 2 * N];
int n;
int a[2 * N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)a[i + n] = a[i], s[i + n] = s[i + n - 1] + a[i];
    //    for(int i=1;i<=2*n;i++)cout<<a[i]<<' ';cout<<endl;
    //    for(int i=1;i<=2*n;i++)cout<<s[i]<<' ';cout<<endl;
    for (int len = 2; len <= 2 * n; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int l = i, r = i + len - 1;
            dpmin[l][r] = INF;
            dpmax[l][r] = -INF;
            for (int j = l; j < r; j++) {
                dpmin[l][r] = min(dpmin[l][j] + dpmin[j + 1][r] + s[r] - s[l - 1], dpmin[l][r]);
                dpmax[l][r] = max(dpmax[l][j] + dpmax[j + 1][r] + s[r] - s[l - 1], dpmax[l][r]);
            }
        }
    }
    int ans1 = INF;
    int ans2 = -INF;
    for (int i = 1, j = n; i <= n; i++, j++) {
        ans1 = min(dpmin[i][j], ans1);
        ans2 = max(dpmax[i][j], ans2);
    }
    cout << ans1 << endl << ans2 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}