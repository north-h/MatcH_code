/*
   Author : north_h
   File : F.cpp
   Time : 2023/7/21/22:30
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

bool cmp(PII c,PII d){
    if(c.se!=d.se)return c.se<d.se;
    return c.fi>d.fi;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mp(n + 1);
    for (auto &i: a) {
        cin >> i;
        if (i <= n)mp[i]++;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + i; j <= n; j += i) {
            mp[j] += mp[i];
        }
    }
//    for (auto i: mp)cout << i << ' ';
//    cout << endl;
    cout << *max_element(ALL(mp)) << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}