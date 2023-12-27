/*
Author : north_h
File : G.cpp
Time : 2023/8/3/16:43
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
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(ALL(a));
    sort(ALL(a), greater<int>());
    vis[0] = true;
    //cout << mx << ' ';
    for (int i = 0; i < 31; i++) {
        int idx = -1;
        int res = mx;
        for (int j = 0; j < n; j++) {
            if (vis[j])continue;
            if ((a[j] | res) > res) {
                res = (mx | a[j]);
                idx = j;
            }
        }
        cout<<idx<<' '<<a[idx]<<endl;
        if (idx == -1)break;
        vis[idx] = true;
        mx |= a[idx];
        //cout << a[idx] << ' ';
    }
    //for (int i = 0; i < n; i++)if (!vis[i])cout << a[i] << ' ';
    cout << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
