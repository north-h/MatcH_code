//
//  Author : north_h
//  File : F.cpp
//  Time : 2023/7/25/12:09
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
#define ll long long
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
const int N = 25010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[M];
int dp[N];
int n;

void solve() {
    cin >> n;
    int ans = n;
    int v = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v = max(v, a[i]);
    }
    sort(a + 1, a + 1 + n);
    met_0(dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[a[i]])ans--;
        for (int j = a[i]; j <= v; j++) {
            dp[j] = max(dp[j - a[i]], dp[j]);
        }
//        for (int j = 0; j <= v; j++)cout << dp[j] << ' ';
//        cout << endl;
    }
    cout << ans << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
