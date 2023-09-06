/*
Author : north_h
File : E.cpp
Time : 2023/7/28/13:24
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
const int N = 200010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], b[N], c[N];
int sa[N], sb[N], sc[N];
int mn[N];

void solve() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i = 0; i < k3; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    int n = k1 + k2 + k3;
    for (int i = 1; i <= n; i++) {
        sa[i] = sa[i - 1] + a[i];
        sb[i] = sb[i - 1] + b[i];
        sc[i] = sc[i - 1] + c[i];
    }
//    for(int i=1;i<=n;i++)cout<<sa[i]<<' ';cout<<endl;
//    for(int i=1;i<=n;i++)cout<<sb[i]<<' ';cout<<endl;
//    for(int i=1;i<=n;i++)cout<<sc[i]<<' ';cout<<endl;
    for (int i = 0; i <= n; i++)mn[i] = sb[i] - sa[i];
    for (int i = 1; i <= n; i++)mn[i] = min(mn[i - 1], mn[i]);
    int ans = INF;
    for (int j = 0; j <= n; j++) {
        int x = mn[j] + sc[j] - sb[j] + sa[n] + sb[n];
        ans = min(ans, x);
    }
    cout << ans << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
