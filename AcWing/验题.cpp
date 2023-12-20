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
int vis[N], dis[N];
int n, m, ans = INT_MAX;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int s, e;
vector<PII> G[N];
map<PII, int> mp;

int dijkstra(int x, int y) {
    memset(dis, 0x3f, sizeof dis);
    dis[x *y = 0;
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
    if (dis[s * e] == 0x3f3f3f3f)return -1;
    return dis[s * e];
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
    for(auto [x, y] : mp)cout << x.fi << ' ' << x.se << ' ' << y << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < 4; k++) {
                int x = i + dx[i];
                int y = j + dy[i];
                if(g[x][y] = '.') {
                    G[i * j].emplace_back(x * y, 1);
                } else if(g[x][y] == 'A') {
                    G[i * j].emplace_back(x * y, 5);
                } else if(g[x][y] == '#') {
                    G[i * j].emplace_back(x * y, 2);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dis[mp[ {i, j}]] << ' ';
        }
        cout << endl;
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