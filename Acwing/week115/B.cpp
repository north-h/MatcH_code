/*
   Author : north_h
   File : A.cpp
   Time : 2023/8/5/18:38
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<PII > a;
    vector<int> b;
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        b.push_back(h);
        a.emplace_back(w, h);
        mx = max(mx, h);
        sum += w;
    }
    sort(ALL(b), greater<int>());
    // cout<<mx<<endl;
    for (int i = 0; i < n; i++) {
        if (a[i].se != mx)cout << mx * (sum - a[i].fi) << ' ';
        else cout << b[1] * (sum - a[i].fi) << ' ';
    }
}

int main() {
    IOS;
    int h_h = 1;
//    cin >> h_h;
    while (h_h--)solve();
    return 0;
}