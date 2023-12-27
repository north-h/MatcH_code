/*
Author : north_h
File : C.cpp
Time : 2023/8/3/14:29
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
const int N = 10;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[N][N];

void solve() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            if (g[i][j] == 'R')cnt++;
        }
        if (cnt == 8) {
            cout << 'R' << endl;
            return;
        }
    }
    for (int i = 0; i < 8; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            if (g[j][i] == 'B')cnt++;
        }
        if (cnt == 8) {
            cout << 'B' << endl;
            return;
        }
    }
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
