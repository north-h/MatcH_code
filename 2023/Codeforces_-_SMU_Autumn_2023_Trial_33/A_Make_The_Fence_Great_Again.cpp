/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-10 23:31:16
 *
 * Problem: A. Make The Fence Great Again
 * Contest: Codeforces - SMU Autumn 2023 Trial 33
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484049/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(3, LLONG_MAX));
    for(int i = 1; i <= n; i++)cin >> a[i] >> b[i];
    dp[1][0] = 0;
    dp[1][1] = b[1];
    dp[1][2] = b[1] * 2;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 2; k++) {
                if(a[i] + j != a[i - 1] + k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
            }
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}