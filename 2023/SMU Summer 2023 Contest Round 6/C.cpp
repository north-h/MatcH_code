//
//  Author : north_h
//  File : C.cpp
//  Time : 2023/7/24/12:26
//                  _   _         _     
// _ __   ___  _ __| |_| |__     | |__  
//| '_ \ / _ \| '__| __| '_ \    | '_ \ 
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|     

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
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 200010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int  dp[N][2];

void solve() {
    met_x(dp);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    dp[0][0] = b;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')dp[i + 1][1] = dp[i][1] + a + b * 2;
        else {
            dp[i + 1][0] = min(dp[i][0] + a + b, dp[i][1] + a * 2 + b);
            dp[i + 1][1] = min(dp[i][0] + a*2 + b * 2, dp[i][1] + a + b * 2);
        }
    }
    cout << dp[n][0] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
