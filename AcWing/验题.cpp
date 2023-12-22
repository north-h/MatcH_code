// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 100010;
const int M = 110;

using namespace std;

int fa[N], szw[N], szv[N];

int find(int x) {
    if(x != fa[x])fa[x] = find(fa[x]);
    return fa[x];
}

struct S {
    int v, w;
};

void solve() {
    int n, m, W;
    cin >> n >> m >> W;
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    vector<int> v(n + 1), w(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
        szw[i] = w[i];
        szv[i] = v[i];
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int pu = find(u);
        int pv = find(v);
        if(pv != pu) {
            fa[pv] = pu;
            szw[pu] += szw[pv];
            szv[pu] += szv[pv];
        }
    }
    vector<int> vis(n + 1);
    vector<S> a;
    for(int i = 1; i <= n; i++) {
        int p = find(i);
        if(vis[p])continue;
        vis[p] = 1;
        a.push_back({szv[p], szw[p]});
    }
    vector<int> dp(W + 1);
    for(int i = 0; i < a.size(); i++) {
        for(int j = W; j >= a[i].v; j--) {
            dp[j] = max(dp[j], dp[j - a[i].v] + a[i].w);
        }
    }
    cout << dp[W] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}