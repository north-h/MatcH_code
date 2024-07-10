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
    for (int i = 2; i <= n; i ++) {
        int p; cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    int time = 1;
    vector<int> in(n + 1), out(n + 1);
    map<int, vector<int>> mp;
    auto dfs = [&](auto dfs, int u, int d, int f) -> void {
        in[u] = time ++;
        mp[d].push_back(in[u]);
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, d + 1, u);
        }
        out[u] = time ++;
    };
    dfs(dfs, 1, 0, 0);
    int _; cin >> _;
    while (_--) {
        int a, b; cin >> a >> b;
        auto x = lower_bound(mp[b].begin(), mp[b].end(), in[a]);
        auto y = lower_bound(mp[b].begin(), mp[b].end(), out[a]);
        cout << y - x << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}