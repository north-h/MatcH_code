//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> g(n + 1);
    vector<array<int, 30>> fa(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<int> depth(n + 1);
    auto dfs = [&](auto && dfs, int u, int f, int d) -> void {
        depth[u] = d;
        fa[u][0] = f;
        for (int i = 1; i <= 22; i ++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u, d + 1);
        }
    };
    dfs(dfs, 1, 0, 0);
    auto lca = [&](int u, int v) -> int {
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

    while (m --) {
        int k; cin >> k;
        vector<int> edge;
        for (int i = 1; i <= k; i ++) {
            int x; cin >> x;
            if (depth[x] > 1) edge.push_back(x);
        }
        sort(edge.begin(), edge.end(), [&](int i, int j) {
            return depth[i] > depth[j];
        });
        bool f = true;
        for (int i = 1; i < edge.size(); i ++) {
            int u = lca(edge[i], edge[i - 1]);
            int d1 = abs(depth[u] - depth[edge[i]]);
            int d2 = abs(depth[u] - depth[edge[i - 1]]);
            if (d1 > 1 && d2 > 1) f = false;
        }
        if (f) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}