/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-08 12:11:26
 *
 * Problem: C. Crazy Robot
 * Contest: Codeforces - SMU Autumn 2023 Trial 31
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484047/problem/C
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

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
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    int x, y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'L')x = i, y = j;
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    auto check = [&](int x, int y) -> bool {
        int res = 0;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 1 || yy < 1 || xx > n || yy > m)continue;
            if(vis[xx][yy] || g[xx][yy] == '#' || g[xx][yy] == 'L')continue;
            res++;
        }
        return res < 2;
    };
    auto bfs = [&](int x, int y) {
        queue<PII> q;
        q.push({x, y});
        vis[x][y] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int xx = t.fi + dx[i];
                int yy = t.se + dy[i];
                if(xx < 1 || yy < 1 || xx > n || yy > m)continue;
                if(vis[xx][yy])continue;
                if(check(xx, yy) && g[xx][yy] == '.') {
                    g[xx][yy] = '+';
                    vis[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
    };
    bfs(x, y);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << g[i][j];
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