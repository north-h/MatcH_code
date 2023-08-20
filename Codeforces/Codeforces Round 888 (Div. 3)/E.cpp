/*
Author : north_h
File : E.cpp
Time : 2023/7/27/12:11
                  _   _         _     
 _ __   ___  _ __| |_| |__     | |__  
| '_ \ / _ \| '__| __| '_ \    | '_ \ 
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|     
*/
//#pragma GCC optimize(3)

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
const int N = 200010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

ll a[N];
int vis[N];
ll cost[N];
vector<int> g[N];
int n, p;

ll dfs(int u) {
    if (vis[u])return cost[u];
    if (!g[u].size())return a[u];
    for (auto i: g[u]) {
        cost[u] += dfs(i);
    }
    cost[u] = min(cost[u], a[u]);
    vis[u]=true;
    return cost[u];
}

void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++)g[i].clear();
    for(int i=1;i<=n;i++)a[i]=0,vis[i]=false,cost[i]=0;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= p; i++) {
        int x;
        cin >> x;
        vis[x] = true;
        cost[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            g[i].push_back(y);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])cost[i] = dfs(i);
        cout << cost[i] << ' ';
    }
    cout << endl;
}


int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
