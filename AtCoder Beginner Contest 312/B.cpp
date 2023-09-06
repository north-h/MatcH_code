/*
   Author : north_h
   File : B.cpp
   Time : 2023/7/29/19:57
                  _   _         _     
 _ __   ___  _ __| |_| |__     | |__  
| '_ \ / _ \| '__| __| '_ \    | '_ \ 
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|
 */
#pragma GCC optimize(3)

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
const int N = 110;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[N][N];
int n,m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> g[i];
    //for(int i=0;i<n;i++)cout<<g[i]<<endl;
    for (int i = 0; i + 9 - 1 < n; i++) {
        for (int j = 0; j + 9 - 1 < m; j++) {
            bool ok = true;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    if (g[k][l] == '.')ok = false;
                }
            }
            //if(i==0&&j==9)cout<<ok<<endl;
            for (int k = i + 6; k < i + 9; k++) {
                for (int l = j + 6; l < j + 9; l++) {
                    if (g[k][l] == '.')ok = false;
                }
            }
            //if(i==0&&j==9)cout<<ok<<endl;
            for (int k = j; k <= j + 3; k++)if (g[i + 3][k] == '#')ok = false;
            for (int k = i; k <= i + 3; k++)if (g[k][j + 3] == '#')ok = false;
            //if(i==0&&j==9)cout<<ok<<endl;
            for (int k = j + 5; k <= j + 8; k++)if (g[i + 5][k] == '#')ok = false;
            for (int k = i + 5; k <= i + 8; k++)if (g[k][j + 5] == '#')ok = false;
            //if(i==0&&j==9)cout<<ok<<endl;
            if (ok)cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}



int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}