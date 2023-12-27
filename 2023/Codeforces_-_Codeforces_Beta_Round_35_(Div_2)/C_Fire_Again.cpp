/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-04 19:23:31
 *
 * Problem: C. Fire Again
 * Contest: Codeforces - Codeforces Beta Round 35 (Div. 2)
 * URL:     https://codeforces.com/contest/35/problem/C
 * MemoryL: 64 MB
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
const int N = 2010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int g[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void bfs() {
    queue<PII> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == 1)q.push({i, j});
        }
    }
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = t.fi + dx[i];
            int y = t.se + dy[i];
            if(x > 0 && y > 0 && x <= n && y <= m && g[x][y] == 0) {
                g[x][y] = g[t.fi][t.se] + 1;
                q.push({x, y});
            }
        }
    }
}

void solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int k;
    cin >> k;
    for(int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        g[x][y] = 1;
    }
    bfs();
    int ans = 0;
    PII pos;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // cout << g[i][j] << ' ';
            if(g[i][j] > ans) {
                ans = g[i][j];
                pos = {i, j};
            }
        }
        // cout << endl;
    }
    cout << pos.fi << ' ' << pos.se << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}