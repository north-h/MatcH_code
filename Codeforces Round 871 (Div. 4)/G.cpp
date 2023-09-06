/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-23 16:58:12
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

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
const int N = 2010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


int dp[N][N];
vector<int> ans;

void solve() {
    int n;
    cin >> n;
    cout << ans[n - 1] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    int t = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = t * t;
            t++;
            dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1] ;
            if(dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0 && j >= 2)
                dp[i][j] -= dp[i - 2][j - 1];
            ans.push_back(dp[i][j]);
        }
    }
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}