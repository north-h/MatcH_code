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