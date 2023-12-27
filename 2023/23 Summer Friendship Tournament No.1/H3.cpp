//
//  Author : north_h
//  File : H3.cpp
//  Time : 2023/7/20/19:26
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

int n;
bool ok;
int ret[N];
map<int, int> mp;

void dfs(int u,int cnt) {
    if(u<0||ok)return ;
    if (mp[u] >= cnt) {
        ret[u]=cnt;
        ok = true;
        return;
    }
    int cntt = cnt - mp[u];
    ret[u]=mp[u];
    dfs(u-1, cntt * 2);
}

void solve() {
    cin >> n;
    vector<int> a(n);
    mp.clear();
    for (int i = 0; i < n; i++)cin >> a[i], mp[a[i]]++;
    ok = false;
    met_0(ret);
    dfs(30, 1);
    if (!ok)cout << "impossible" << endl;
    else {
        for (int i = 0; i < n; i++) {
            if (ret[a[i]])cout << 1, ret[a[i]]--;
            else cout << 0;
        }
        cout << endl;
    }
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
