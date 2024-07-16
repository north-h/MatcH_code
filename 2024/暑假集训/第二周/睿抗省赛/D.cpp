#include<bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << '\n'
#define debug2(a, b) cout << #a << '=' << a << #b << '=' << b << '\n'
#define int long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u] ++, d[v] ++;
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << i << ':';
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    // for (int i = 1; i <= n; i ++) {
    //     cout << d[i] << " \n"[i == n];
    // }
    queue<int> q;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        // debug1(t);
        for (auto v : g[t]) {
            if (vis[v]) continue;
            d[v] --;
            if (d[v] == 1) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << d[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i ++) {
    //     cout << vis[i] << " \n"[i == n];
    // }
    bool ok = true;
    int c = 0, C = 0;
    vector<int> vi(n + 1);
    auto dfs = [&](auto & dfs, int u) -> void {
        vi[u] ++;
        if (d[u] != 2) ok = false;
        for (auto v : g[u]) {
            if (vi[v] || vis[v]) continue;
            dfs(dfs, v);
        }
    };
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 2) {
            c ++;
            if (!vi[i]) {
                ok = true;
                dfs(dfs, i);
                if (ok) C ++;
            }
        }
    }
    if (C != 1) {
        cout << "No " << C << '\n';
    } else {
        cout << "Yes " << c << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}

