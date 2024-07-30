// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans = 0;
    vector<int> val;
    auto dfs = [&](auto && dfs, int u, int cnt) -> void {
        ans = max(ans, cnt);
        for (auto v : g[u]) {
            int idv = val[u];
            if (val[v] >= val[u]) continue;
            for (auto vv : g[u]) {
                if (vv != v) val[vv] = -- idv;
            }
            val[v] = idv;
            dfs(dfs, v, cnt + 1);
            for (auto vv : g[u]) val[vv] = -1;
        }
    };
    for (int i = 1; i <= n; i ++) {
        vector<int> (n + 1, -1).swap(val);
        val[i] = n + 10;
        dfs(dfs, i, 1);
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