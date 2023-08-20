/*
   Author : north_h
   File : G.cpp
   Time : 2023/7/22/2:00
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
#define int128 __int128
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.end()
#define endl '\n'
const int N = 200010;
const int M = 110;
const int MOD = 1e9 + 7;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int dg = 1, udg = 1;
    map<int, int> row, col, pt;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        row[y]++;
        col[x]++;
        pt[abs(x - y)]++;
        if (x == y)dg++;
        if (abs(x) == abs(y))udg++;
    }
    ll ans = dg * (dg - 1) + udg * (udg - 1) ;
    for (auto [x, y]: row) {
        if(x==0)y++;
        ans += y * (y - 1);
    }
    for (auto [x, y]: col) {
        if(x==0)y++;
        ans += y * (y - 1);
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