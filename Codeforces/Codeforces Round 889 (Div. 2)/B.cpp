/*
   Author : north_h
   File : B.cpp
   Time : 2023/7/29/22:28
                  _   _         _     
 _ __   ___  _ __| |_| |__     | |__  
| '_ \ / _ \| '__| __| '_ \    | '_ \ 
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|
 */
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define uint unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define Aint(a) a.begin(),a.end()
#define rAint(a) a.begin(),a.end()
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
//    map<int, int> mp;
//    int xx = n;
//    for (int i = 2; i <= xx / i; i++) {
//        if (xx % i == 0) {
//            int cnt = 0;
//            while (xx % i == 0)xx /= i, cnt++;
//            mp[i] = cnt;
//        }
//    }
//    if (xx > 1)mp[xx] = 1;
//    if(n==1){
//        cout<<1<<endl;
//        return ;
//    }
//    int ans = 0;
//    for (auto [x, y]: mp){
//        int cnt=0;
//        for(int i=x;i>=1;i--){
//            if(n%i==0)cnt++;
//            else break;
//        }
//        for(int i=x+1;;i++){
//            if(n%i==0)cnt++;
//            else break;
//        }
//        ans=max(ans,cnt);
//        //cout<<x<<' '<<y<<endl;
//    }
    int ans = 0;
    for (int i = 1;; i++) {
        if (n % i == 0)ans++;
        else break;
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