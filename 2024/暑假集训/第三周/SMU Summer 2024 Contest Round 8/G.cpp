// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, zj, node, ok, ans, cnt;
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
    // debug2(u, f);
    // debug2(d, zj / 2);
    if (d == zj / 2) {
        vis[f] = 2;
        ans *= (int)g[f].size();
        cnt += g[f].size() - 1;
        return ;
    }
    for (auto v : g[u]) {
        // debug2(u, v);
        if (v == f || vis[v]) continue;
        vis[v] = 1;
        dfs2(v, u, d + 1);
        if (vis[u] == 2) return ;
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
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ':';
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    zj = 0;
    dfs(1, 0, 0);
    int root = node;
    dfs(node, 0, 0);
    zjd.push_back(root);
    ok = 0;
    dfs1(root, 0, 0);
    // debug2(root, zj);
    // for (auto i : zjd) cout << i << ' ';
    // cout << '\n';
    // cout << zjd.size() << '\n';
    if (zjd.size() == 1) {
        cout << 0 << '\n';
    } else if (zjd.size() == 2) {
        cout << 1 << '\n';
    } else if (zjd.size() == 3) {
        int c = g[zjd[1]].size();
        cout << pow(2, c) - 1 - c << '\n';
    } else {
        int N = zjd.size();
        int v1, v2;
        ans = 1;
        vector<int> (n + 1).swap(vis);
        if (zj % 2 == 0) {
            v1 = zjd[N / 2];
            // debug1(v1);
            vis[v1] = 1;
            dfs2(v1, 0, 0);
            dfs2(v1, 0, 0);
        } else {
            v1 = zjd[N / 2], v2 = zjd[N / 2 - 1];
            vis[v1] = vis[v2] = 1;
            // debug2(v1, v2);
            // debug1(n);
            // for (int i = 1; i <= n; i ++) cout << vis[i] << ' ';
            // cout << '\n';
            dfs2(v1, 0, 0);
            // for (int i = 1; i <= n; i ++) cout << vis[i] << ' ';
            // cout << '\n';
            dfs2(v2, 0, 0);
        }
        // debug1(cnt);
        cout << ans - 1 - cnt << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}