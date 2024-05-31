/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-25 22:43:17
 *
 * Problem: D. Paint the Tree
 * Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1975/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<vector<int>> g(n + 1);
    vector<int> fa(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1);
    auto dfs = [&](auto dfs, int u, int f) -> void {
        for (auto v : g[u]) {
            if (v == f) continue;
            d[v] = d[u] + 1;
            fa[v] = u;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, a, -1);
    int dab = (d[b] + 1) / 2;
    int root = b;
    for (int i = 1; i <= dab; i ++) {
        root = fa[root];
    }
    for (int i = 1; i <= n; i ++) d[i] = 0;
    dfs(dfs, root, -1);
    int mx = *max_element(d.begin() + 1, d.end());
    cout << 2 * (n - 1) - mx + dab << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}