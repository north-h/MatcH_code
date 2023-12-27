/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-01 11:14:12
 *
 * Problem: AT_dp_c Vacation
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/AT_dp_c
 * MemoryL: 1024 MB
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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i] >> b[i] >> c[i];
    // for(int i = 1; i <= n; i++)cin >> b[i];
    // for(int i = 1; i <= n; i++)cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + b[i], dp[i - 1][2] + c[i]);
        dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][2] + c[i]);
        dp[i][2] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + b[i]);
        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}