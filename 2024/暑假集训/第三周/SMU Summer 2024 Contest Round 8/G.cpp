// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

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
    if (d == zj) ok = 1;
    if (ok) return ;
    for (auto v : g[u]) {
        if (v == f) continue;
        zjd.push_back(v);
        dfs1(v, u, d + 1);
        if (ok) return ;
        zjd.pop_back();
    }
}

int dfs2(int u, int d, int f) {
    int res = 0;
    if (d == 0) return 1;
    for (auto v : g[u]) {
        if (v == f) continue;
        res += dfs2(v, d - 1, u);
    }
    return res;
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    int root = node;
    dfs(node, 0, 0);
    zjd.push_back(root);
    dfs1(root, 0, 0);
    int N = zjd.size();
    int v1, v2;
    ans = 1;
    vector<int> (n + 1).swap(vis);
    if (N & 1) {
        v1 = zjd[N / 2];
        for (auto i : g[v1]) {
            int ss = dfs2(i, zj / 2 - 1, v1);
            cnt += ss;
            ans *= (ss + 1);
            ans %= mod;
        }
        ans -= (cnt + 1);
    } else {
        v1 = zjd[N / 2], v2 = zjd[N / 2 - 1];
        ans *= dfs2(v1, zj / 2, v2);
        ans %= mod;
        ans *= dfs2(v2, zj / 2, v1);
        ans %= mod;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}