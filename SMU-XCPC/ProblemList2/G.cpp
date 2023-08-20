//
//  Author : north_h
//  File : G.cpp
//  Time : 2023/7/21/10:08
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
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

inline ll read() {
    ll x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

ll ksm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res*=x;
        x=x*x;
        y>>=1;
    }
    return res;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll x = l ^ r;
    ll ans = 0;
    ll cnt = 0;
    while (x) {
        x /= 2;
        cnt++;
        ans = ans * 2 + 1;
    }
    cout << anss << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
