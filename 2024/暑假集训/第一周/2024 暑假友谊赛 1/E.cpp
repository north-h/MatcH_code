// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dis = 0, ok = 0;
    vector<int> t, tt;
    auto dfs = [&](auto &&dfs, int u, int d, int f) -> void {
        if(ok) return ;
        if (u == n) {
            ok = 1;
            dis = d;
            t = tt;
            return ;
        }
        for (auto v : g[u]) {
            if (v == f) continue;
            tt.push_back(v);
            dfs(dfs, v, d + 1, u);
            tt.pop_back();
        }
    };
    tt.push_back(1);
    dfs(dfs, 1, 0, 0);
    set<int> st;
    vector<int> vis(n + 1);
    for (auto i : tt) st.insert(i);
    for (auto i : st) cout <<  i << ' '; cout << '\n';
    auto dfs2 = [&](auto &&dfs, int u, int f) -> void {
        vis[u] = 1;
        for(auto v : g[u]) {
            if (v == f || st.count(v)) continue;
            dfs(dfs, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i ++) cnt += vis[i];
    debug2(dis, cnt);
    int cf = dis / 2 + cnt;
    int cs = n - cf;
    if (cf > cs) cout << "Fennec" << '\n';
    else cout << "Snuke" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}