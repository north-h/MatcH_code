/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-28 12:33:46
 *
 * Problem: A. Mortal Kombat Tower
 * Contest: Codeforces - SMU Autumn 2023 Trial 25
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481917/problem/A
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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    // vector<vector<int>> dp(n + 1, vector<int>(2, INF));//0->先手,1->后手
    // dp[0][1] = 0;
    // dp[1][0] = a[1];
    // for(int i = 2; i <= n; i++) {
    //     dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i] + a[i - 1]);
    //     dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
    //     // debug2(dp[i][0], dp[i][1]);
    // }
    // cout << min(dp[n][0], dp[n][1]) << endl;
    int cnt = 0;
    int ans = (a[1] == 1);
    for(int i = 2; i <= n; i++) {
        if(a[i] == 1)cnt++;
        else {
            ans += cnt / 3;
            cnt = 0;
        }
    }
    cout << ans + cnt / 3 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}