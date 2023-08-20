//
//  Author : north_h
//  File : G.cpp
//  Time : 2023/7/20/18:14
//                  _   _         _     
// _ __   ___  _ __| |_| |__     | |__  
//| '_ \ / _ \| '__| __| '_ \    | '_ \ 
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|     

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
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<int> g[N];
bool vis[N];
int w[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)w[i] = 1;
    met_0(vis);
    vector<ll> ans;
    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = true;
        for (auto i: g[u]) {
            if (!vis[i]) {
                dfs(i);
                w[u] += w[i];
            }
        }
    };
    dfs(1);
    for (int i = 1; i <= n; i++)ans.push_back(1ll * w[i] * (n - w[i]));
    sort(ALL(ans));
    ll res = 0;
    for (int i = 1; i < n; i++) res += ans[i] * (n - i);
    cout << res << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
