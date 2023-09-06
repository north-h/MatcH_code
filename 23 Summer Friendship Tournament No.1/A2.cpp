//
//  Author : north_h
//  File : A2.cpp
//  Time : 2023/7/20/15:27
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
const int N = 100100;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[M][N];
int vis[N]{};
bool ok;
int n, m, a, b;

void dfs(int row, int num){
    if (row > n || num > a || ok)return;
    set<int> line;
    for (int i = 0; i < n; i++) {
        if (vis[i])continue;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*')line.insert(j);
        }
    }
    if (line.size() <= b) {
        ok = true;
        return;
    }
    vis[row] = true;
    dfs(row + 1, num + 1);

    vis[row] = false;
    dfs(row + 1, num);
};

void solve() {
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    met_0(vis);
    ok=false;
    dfs(0, 0);
    if (ok)cout << "yes" << endl;
    else cout << "no" << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
