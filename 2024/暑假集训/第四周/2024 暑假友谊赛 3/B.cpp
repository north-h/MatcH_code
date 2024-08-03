// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) continue;
            if (a[i] % a[j] == 0 && a[i] / a[j] == 3) g[i].push_back(j);
            if (a[i] * 2 == a[j]) g[i].push_back(j);
        }
    }
    vector<int> vis, t;
    bool ok = false;
    auto dfs = [&](auto && dfs, int u) -> void {
        if (ok) return ;
        if (t.size() == n) {
            for (auto i : t) cout << a[i] << ' ';
            cout << '\n';
            ok = true;
            return ;
        }
        for (auto v : g[u]) {
            vis[v] = 1;
            t.push_back(v);
            dfs(dfs, v);
            vis[u] = 0;
            t.pop_back();
        }
    };
    for (int i = 1; i <= n; i ++) {
        vector<int>(n + 1).swap(vis);
        t.clear();
        ok = false;
        vis[i] = 1;
        t.push_back(i);
        dfs(dfs, i);
        if (ok) break;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}