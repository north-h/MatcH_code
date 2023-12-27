//
//  Author : north_h
//  File : Y.cpp
//  Time : 2023/7/18/10:07
//

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
#define endl '\n'
const int N = 110;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

//vector<PII> g[N];
int c, n, m;
int vis[N];
int dis[N];
int g[N][N];

int prim() {
    int res = 0;
    met_x(dis);
    for (int i = 0; i < m; i++) {
        int t = -1;
        for (int j = 1; j <= m; j++) {
            if (!vis[j] && (t == -1 || dis[j] < dis[t])) {
                t = j;
            }
        }
        if (dis[t] == INF && i)return INF;
        vis[t] = true;
        if(i)res += dis[t];
        for (int j = 1; j <= m; j++)dis[j] = min(dis[j], g[t][j]);
    }
    return res;
}

void solve() {
    met_x(g);
    cin >> c >> n >> m;
    while (n--) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = min(g[y][x], w);
    }
    //cout<<prim()<<endl;
    if (prim() > c)cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
