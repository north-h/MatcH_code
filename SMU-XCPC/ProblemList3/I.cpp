/*
Author : north_h
File : I.cpp
Time : 2023/7/28/16:52
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
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int dp[N][2];
int a[N];
bool vis[N];
vector<int> g [N];
int n;

void dfs(int u) {
    dp[u][1] = a[u];
    for (auto i: g[u]) {
        dfs(i);
        dp[u][1] += dp[i][0];
        dp[u][0] += max(dp[i][0], dp[i][1]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)break;
        g[y].push_back(x);
        vis[x] = true;
    }
    int root;
    for (int i = 1; i <= n; i++)if (!vis[i])root = i;
    dfs(root);
    int ans=0;
    cout << max(dp[root][1], dp[root][0]) << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
