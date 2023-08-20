/*
   Author : north_h
   File : L.cpp
   Time : 2023/8/1/22:24
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
const int N = 110;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

bool v1[N], v2[N], v_huan[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pre[n + 10], post[n + 10];
    bool ok = true;
    while (m--) {
        int a, b;
        cin >> a >> b;
        pre[a].push_back(b);
        post[b].push_back(a);
        if (a == b) ok = false;
    }
    int pre1 = 0;
    int post2 = 0;
    bool huan = false;
//    for(int i=1;i<=n;i++){
//        cout<<i<<':';
//        for(auto j:pre[i])cout<<j<<' ';
//        cout<<endl;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<i<<':';
//        for(auto j:post[i])cout<<j<<' ';
//        cout<<endl;
//    }
    function<void(int)> dfs1 = [&](int u) {
        v1[u] = true;
        for (auto i: pre[u]) {
            if (!v1[i]) {
                pre1++;
                dfs1(i);
            }
        }
    };
    function<void(int)> dfs2 = [&](int u) {
        v2[u] = true;
        for (auto i: post[u]) {
            if (!v2[i]) {
                post2++;
                dfs2(i);
            }
        }
    };
    function<void(int)> dfs_huan = [&](int u) {
        if (ok)return;
        v_huan[u] = true;
        for (auto i: post[u]) {
            if (v_huan[i]) {
                ok = true;
                return;
            }
            dfs_huan(i);
        }
    };
    string s;
    for (int i = 0; i <= n; i++)s += '0';
    if (!ok) {
        cout << s.substr(1) << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        met_0(v1);
        met_0(v2);
        post2 = pre1 = 0;
        huan = false;
        dfs1(i);
        dfs2(i);
        dfs_huan(i);
        if (huan) {
            cout << s.substr(1) << endl;
            return;
        }
        if (pre1 == post2 || (pre1 + post2 != n && pre1 <= n / 2 && post2 <= n / 2)) s[i] = '1';
    }
    cout << s.substr(1) << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}