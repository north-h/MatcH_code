/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-18 20:02:38
 *
 * Problem: E - Stamp
 * Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2023（AtCoder Beginner Contest 329）
 * URL:     https://atcoder.jp/contests/abc329/tasks/abc329_e
 * MemoryL: 1024 MB
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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    s = " " + s;
    t = " " + t;
    // debug2(s, t);
    vector<array<int, 6>> dp(n + 1);
    if(s[1] == t[1]) {
        dp[1][1] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i - 1][j]) {
                if(s[i] == t[1])dp[i][1] = 1;
                if(j + 1 <= m && s[i] == t[j + 1])dp[i][j + 1] = 1;
                if(j == m) {
                    for(int k = 1; k <= m; k++) {
                        if(s[i] == t[k])dp[i][k] = 1;
                    }
                }
            }
        }
    }
    cout << (dp[n][m] ? "Yes" : "No") << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}