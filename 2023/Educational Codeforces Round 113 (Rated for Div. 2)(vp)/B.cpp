/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-08 23:11:14
 * =====================================
 * Thirty years east, thirty years west,
 * don't you dare bully me because I'm poor now.
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
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
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 55;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int vis[N][N];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    met_0(vis);
    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '2')a.push_back(i);
    }
    if(a.size() == 2 || a.size() == 1) {
        cout << "NO" << endl;
        return ;
    }
    if(a.size()) {
        for(int i = 0; i < a.size() - 1; i++)vis[a[i]][a[i + 1]] = 1, vis[a[i + 1]][a[i]] = 2;
        vis[a[a.size() - 1]][a[0]] = 1;
        vis[a[0]][a[a.size() - 1]] = 2;
    }
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // cout<<vis[i][j]<<' ';
            if(i == j)cout << 'X';
            else if(vis[i][j] == 1)cout << '+';
            else if(vis[i][j] == 2)cout << '-';
            else cout << '=';
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}