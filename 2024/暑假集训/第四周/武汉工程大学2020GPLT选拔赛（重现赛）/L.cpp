// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int depth[N];
int fa[N][25];
vector<vector<int>> g;

void dfs(int u, int f) {
    depth[u] = depth[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 22; i ++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
};

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 22; i >= 0; i --) {
        if (depth[fa[u][i]] >= depth[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return v;
    for (int i = 22; i >= 0; i --) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
};


void solve() {
    int n, q; cin >> n >> q;
    vector<int> p(n + 1);
    g.resize(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        p[v] = u;
    }
    int root = 1;
    while (p[root]) root ++;
    dfs(root, 0);
    while (q --) {
        int u, v; cin >> u >> v;
        int gg = lca(u, v);
        int l = depth[gg];
        int dis = depth[u] - l + depth[v] - l;
        if (gg == u || gg == v || dis <= 4) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
        cout << dis << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}