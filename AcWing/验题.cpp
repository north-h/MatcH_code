// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 110;
const int M = 110;

using namespace std;

char g[N][N];
int vis[N][N], dis[N][N];
int n, m, ans = INT_MAX;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int s, e;
vector<PII> G[N];
map<PII, int> mp;

int dijkstra(int x,int y) {
    memset(dis, 0x3f, sizeof dis);
    dis[mp[{x,y}]] = 0;
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (t == -1 || dis[j] < dis[t])) {
                t = j;
            }
        }
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        vis[t] = 1;
    }
    if (dis[n] == INF)return -1;
    return dis[n];
}


void solve() {
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            mp[ {i, j}] = i * j;
            if(g[i][j] == 'S')x = i, y = j;
            if(g[i][j] == 'T')s = i, e = j;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < 4; k++) {
                int x = i + dx[i];
                int y = j + dy[i];
                if(g[x][y] = '.') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 1);
                } else if(g[x][y] == 'A') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 5);
                } else if(g[x][y] == '#') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 5);
                }
            }
        }
    }
    cout << dijkstra(x,y) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}