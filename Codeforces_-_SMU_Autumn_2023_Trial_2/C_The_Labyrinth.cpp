/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-28 12:38:56
 *
 * Problem: C. The Labyrinth
 * Contest: Codeforces - SMU Autumn 2023 Trial 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475545/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char vis[N][N], g[N][N];
map<int, int> mp;
int n, m ;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int bfs(int x, int y) {
    vector<vector<int>> vi(n + 1, vector<int> (m + 1));
    queue<PII> q;
    q.push({x, y});
    vi[x][y] = 1;
    int res = 0;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 1 && yy >= 1 && xx <= n && yy <= m && !vi[xx][yy] && g[xx][yy] == '.') {
                res++;
                q.push({xx, yy});
                vi[xx][yy] = 1;
            }
        }
    }
    return res + 1;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            // vis[i][j] == '#';
        }
    }
    int t = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == '*') {
                vis[i][j] = bfs(i, j) + '0';
            } else vis[i][j] = '.';
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << vis[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}