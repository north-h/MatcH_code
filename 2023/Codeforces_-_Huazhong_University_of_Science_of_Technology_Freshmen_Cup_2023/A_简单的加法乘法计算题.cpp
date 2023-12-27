/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-27 12:55:38
 *
 * Problem: A. 简单的加法乘法计算题
 * Contest: Codeforces - Huazhong University of Science of Technology Freshmen Cup 2023
 * URL:     https://codeforces.com/gym/104728/problem/A
 * MemoryL: 512 MB
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
const int N = 500010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int y, n, m;
    cin >> y >> n >> m;
    vector<int> b(m), q(y + 1), dp(y + 1, INF);
    for(auto &i : b)cin >> i;
    int tt = 0, hh = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    q[++tt] = 1;
    for(int i = n + 1; i <= y; i++) {
        for(auto j : b) {
            if(i % j == 0) {
                dp[i] = min(dp[i], dp[i / j] + 1);
            }
        }
        dp[i] = min(dp[i], dp[q[hh]] + 1);
        if(hh <= tt && i - q[hh] > n)hh++;
        while(hh <= tt && dp[q[tt]] >= dp[i])tt--;
        q[++tt] = i;
    }
    cout << dp[y] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}