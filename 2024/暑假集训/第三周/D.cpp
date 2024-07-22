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
    vector<array<int, 2>> a(n + 1);
    vector<int> fa(n + 1);
    for (int i = 1; i < n; i ++)  {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        a[i] = {u, v};
    }
    int cnt = 0;
    map<array<int, 2>, int> mp;
    auto dfs = [&](auto && dfs, int u, int f) -> void {
        int idx = 0, ii = mp[{f, u}];
        for (auto v : g[u]) {
            if (v == f) continue;
            idx ++;
            if (idx == ii) idx ++;
            mp[{u, v}] = idx;
            dfs(dfs, v, u);
        }
        cnt = max(idx, cnt);
    };
    dfs(dfs, 1, 0);
    cout << cnt << '\n';
    for (int i = 1; i < n; i ++) {
        cout << mp[ {a[i][0], a[i][1]}] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}