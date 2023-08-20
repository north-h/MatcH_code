/*
Author : north_h
File : B.cpp
Time : 2023/7/31/11:51
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
const int N = 100010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ng(n + 10, vector<char>(m + 10));
    vector<vector<int>> gg(n + 10, vector<int>(m + 10));
    vector<int> a(n * m + 10);
    vector<int> dg(n * m + 10);
    vector<vector<int>> g(n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ng[i][j];
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << ng[i][j] << ' ';
//        }
//        cout << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> gg[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cout << ng[i][j] << endl;
            if (ng[i][j] == 'l' && j - gg[i][j] >= 1) {
                g[(i - 1) * m + j].push_back((i - 1) * m + j - gg[i][j]);
                dg[(i - 1) * m + j - gg[i][j]]++;
            } else if (ng[i][j] == 'r' && j + gg[i][j] <= m) {
                g[(i - 1) * m + j].push_back((i - 1) * m + j + gg[i][j]);
                dg[(i - 1) * m + j + gg[i][j]]++;
            } else if (ng[i][j] == 'u' && i - gg[i][j] >= 1) {
                g[(i - 1) * m + j].push_back((i - 1) * m + j - gg[i][j] * m);
                dg[(i - 1) * m + j - gg[i][j] * m]++;
            } else if (ng[i][j] == 'd' && i + gg[i][j] <= n) {
                g[(i - 1) * m + j].push_back((i - 1) * m + j + gg[i][j] * m);
                //g[3].push_back(6);
                dg[(i - 1) * m + j + gg[i][j] * m]++;
            }
        }
    }
//    for (int i = 1; i <= n * m; i++) {
//        cout << i << ':';
//        for (auto j: g[i])cout << j << ' ';
//        cout << endl;
//    }
//    for (int i = 1; i <= n * m; i++)cout << dg[i] << ' ';
//    cout << endl;
    vector<int> vis(n * m + 10);
    bool ok = true;
    int res = 0;
    function<void(int)> dfs = [&](int u) -> void {
        if (!ok)return;
        vis[u] = true;
        res++;
        for (auto i: g[u]) {
            if (vis[i]) {
                if (res < n * m)ok = false;
                return;
            }
            dfs(i);
        }
    };
    int root = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)if (dg[i] == 0)root = i, cnt++;
    dfs(root);
    //cout << res << endl;
    if (ok && res == n * m || cnt > 1)cout << "Yes" << endl;
    else cout << "No" << endl;
}
/*1
2 2
rd
ul
1 1
1 1
 */

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
