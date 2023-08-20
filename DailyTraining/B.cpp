/*
   Author : north_h
   File : B.cpp
   Time : 2023/7/19/22:01
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
#define  a_ a a.begin(),a.end()
#define endl '\n'
const int N = 200010;
const int M = 110;
const int MOD = 1e9 + 7;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

inline int read() {
    int x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

ll n, m;

bool check(ll x) {
    __int128 res =  x * (n - 1) -  x * (x - 1) / 2;
    if (res <= m)return true;
    else return false;
}

void solve() {

    cin >> n >> m;
    ll l = 0, r = n-1;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l + 1 << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}