/*
Author : north_h
File : A.cpp
Time : 2023/8/1/11:56
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
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int y1, m1, d1, y2, m2, d2;
    string s;
    cin >> y1 >> m1 >> d1 >> s >> y2 >> m2 >> d2;
    map<string, int> mp1;
    map<int, string> mp2;
    mp1["Monday"] = 1;
    mp1["Tuesday"] = 2;
    mp1["Wednesday"] = 3;
    mp1["Thursday"] = 4;
    mp1["Friday"] = 5;
    mp2[1] = "Monday";
    mp2[2] = "Tuesday";
    mp2[3] = "Wednesday";
    mp2[4] = "Thursday";
    mp2[0] = "Friday";
    int x = y1 * 360 + m1 * 30 + d1;
    int y = y2 * 360 + m2 * 30 + d2;
    if (y == x)cout << mp2[x];
    else if (x < y) {
        int dis = ((y - x) % 5 + mp1[s]) % 5;
        cout << mp2[dis] << endl;
    } else {
        int dis = (mp1[s] - (x - y) % 5 + 5) % 5;
        cout << mp2[dis] << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
