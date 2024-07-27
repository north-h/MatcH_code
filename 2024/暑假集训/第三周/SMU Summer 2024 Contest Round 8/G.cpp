// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, zj, node, ok, ans;
vector<vector<int>> g;
vector<int> zjd, vis;


void dfs(int u, int f, int d) {
    if (zj < d) {
        zj = d;
        node = u;
    }
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs(v, u, d + 1);
    }
}

void dfs1(int u, int f, int d) {
    // debug2(u, d);
    if (d == zj) ok = 1;
    if (ok) return ;
    for (auto v : g[u]) {
        if (v == f) continue;
        zjd.push_back(v);
        // debug2(u, v);
        dfs1(v, u, d + 1);
        if (ok) return ;
        zjd.pop_back();
    }
}

void dfs2(int u, int f, int d) {
    debug2(u, f);
    if (d == zj / 2) {
        vis[u] = 1;
        ans *= (g[f].size() + 1);
        return ;
    }
    for (auto v : g[u]) {
        if (v == f || vis[v]) continue;
        debug2(v, u);
        vis[v] = 1;
        dfs(v, u, d + 1);
        if (vis[u]) return ;
    }
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        cout << i << ':';
        for (auto j : g[i]) cout << j << ' ';
        cout << '\n';
    }
    zj = 0;
    dfs(1, 0, 0);
    int root = node;
    dfs(node, 0, 0);
    zjd.push_back(root);
    ok = 0;
    debug2(root, zj);
    dfs1(root, 0, 0);
    for (auto i : zjd) cout << i << ' ';
    cout << '\n';
    cout << zjd.size() << '\n';
    if (zjd.size() == 1) {
        cout << 0 << '\n';
    } else if (zjd.size() == 2) {
        cout << 1 << '\n';
    } else if (zjd.size() == 3) {
        int c = g[zjd[1]].size();
        cout << pow(2, c) - 1 - c << '\n';
    } else {
        int n = zjd.size();
        int v1, v2;
        ans = 1;
        vector<int> (n + 1).swap(vis);
        if (zj % 2 == 0) {
            v1 = zjd[n / 2 - 1];
            vis[v1] = 1;
            dfs2(v1, 0, 0);
        } else {
            v1 = zjd[n / 2], v2 = zjd[n / 2 - 1];
            vis[v1] = vis[v2] = 1;
            debug2(v1, v2);
            dfs2(v1, 0, 0);
            // dfs2(v2, 0, 0);
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}