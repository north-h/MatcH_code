//
//  Author : north_h
//  File : B.cpp
//  Time : 2023/7/24/12:06
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
const int N = 100;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int n,m;
int g[N][N];
int vis[N][N];

void solve() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0)cnt++;
        }
    }
    if (cnt == n * m) {
        cout << 0 << endl;
        return;
    }
    vector <PII> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (g[i][j] == 1 && g[i][j + 1] == 1 && g[i + 1][j] == 1 && g[i + 1][j + 1] == 1) {
                ans.push_back({i + 1, j + 1});
                vis[i][j] = vis[i][j + 1] = vis[i + 1][j] = vis[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != g[i][j]) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans)cout << i.fi << ' ' << i.se << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
