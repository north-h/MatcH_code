/*
   Author : north_h
   File : D.cpp
   Time : 2023/7/21/7:36
                  _   _         _
 _ __   ___  _ __| |_| |__     | |__
| '_ \ / _ \| '__| __| '_ \    | '_ \
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|
 */

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,-0x3f,sizeof a)
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
#define int128 __int128
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.end()
#define endl '\n'
const int N = 55;
const int M = 1100;
const int MOD = 1e9 + 7;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int dp[N][N][N][N];
string a, b;

void solve() {
    met_0(dp);
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int ans = 1;
    for (int aa = 0; aa <= a.size(); aa++) {
        for (int bb = 0; bb <= b.size(); bb++) {
            for (int i = 1, j = aa; j < a.size(); i++, j++) {
                for (int k = 1, l = bb; l < b.size(); k++, l++) {
                    if (aa + bb <= 1) dp[i][j][k][l] = 1;
                    else {
                        if (aa >= 2 && a[i] == a[j])dp[i][j][k][l] |= dp[i + 1][j - 1][k][l];
                        if (bb >= 2 && b[k] == b[l])dp[i][j][k][l] |= dp[i][j][k + 1][l - 1];
                        if (aa && bb && a[i] == b[l])dp[i][j][k][l] |= dp[i + 1][j][k][l - 1];
                        if (aa && bb && a[j] == b[k])dp[i][j][k][l] |= dp[i][j - 1][k + 1][l];
                    }
                    if (dp[i][j][k][l])ans = max(ans, aa + bb);
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}

