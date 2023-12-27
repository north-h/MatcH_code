/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-09 19:04:57
 *
 * Problem: A. Bicolorings
 * Contest: Codeforces - SMU Autumn 2023 Trial 32
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484048/problem/A
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

ll dp[N][N * 2][4];

void solve() {
    int n, k;
    cin >> n >> k;
    met_0(dp);
    // vector<vector<vector<ll>>> dp(vector<ll>(n + 1, vector<ll>(n * 2 + 1, vector<ll>(4, 0))));
    dp[1][1][0] = dp[1][1][3] = dp[1][2][1] = dp[1][2][2] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i * 2; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3];
            dp[i][j][3] = dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3];
            dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3];
            if(j >= 2) {
                dp[i][j][1] += dp[i - 1][j - 2][2];
                dp[i][j][2] += dp[i - 1][j - 2][1];
            }
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
            dp[i][j][2] %= MOD;
            dp[i][j][3] %= MOD;
        }
    }
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}