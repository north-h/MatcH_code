// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vis(n + 1);
    int idx = 1;
    auto dfs = [&](auto self, int u) -> void{
        vis[u] = idx;
        for (auto i : g[u]) {
            if (vis[i]) continue;
            self(self, i);
        }
    };
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(dfs, i);
            idx ++;
        }
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) mp[vis[i]] = i;
    int ans = 0;
    bool ok = false;
    vector<int> vi(n + 1);
    auto dfs1 = [&](auto self, int u, int f) -> void{
        if (ok) return ;
        for (auto i : g[u]) {
            if (i == f) continue;
            if (vi[i]) {
                ok = true;
                return ;
            }
            vi[i] = 1;
            self(self, i, u);
        }
    };
    // for (int i = 1; i <= n; i ++) cout << vis[i] << " \n"[i == n];
    for (int i = 1; i < idx; i ++) {
        vi.assign(n + 1, 0);
        ok = false;
        vi[mp[i]] = 1;
        dfs1(dfs1, mp[i], 0);
        if (ok) ans ++;
    }
    cout << idx - 1 << ' ' << ans << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}