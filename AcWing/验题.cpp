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
int vis[N * N], dis[N * N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int s, e, x, y;
vector<PII> G[N];
map<PII, int> mp;

int dijkstra(int x, int y) {
    memset(dis, 0x3f, sizeof dis);
    dis[mp[ {x, y}]] = 0;
    priority_queue<PII, vector<PII >, greater<PII>> heap;
    heap.push({dis[mp[{x, y}]], mp[{x, y}]});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (vis[t.se])continue;
        vis[t.se] = 1;
        for (auto [x, y] : G[t.se]) {
            if (dis[x] > dis[t.se] + y) {
                dis[x] = dis[t.se] + y;
                heap.push({dis[x], x});
            }
        }
    }
    if (dis[mp[ {s, e}]] == 0x3f3f3f3f)return -1;
    return dis[mp[ {s, e}]];
}


void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            mp[ {i, j}] = i * m + j + 1;
            if(g[i][j] == 'S')x = i, y = j;
            if(g[i][j] == 'T')s = i, e = j;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'K')continue;
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == 'K')continue;
                if(g[x][y] == '.' || g[x][y] == 'T' || g[x][y] == 'S') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 1);
                } else if(g[x][y] == 'A') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 4);
                } else if(g[x][y] == '#') {
                    G[mp[ {i, j}]].emplace_back(mp[ {x, y}], 2);
                }
            }
        }
    }
    cout << dijkstra(x, y) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}