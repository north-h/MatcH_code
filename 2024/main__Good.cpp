#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;

int n, m;
vector<pair<int, int>> g[N];
int x[N * 2], y[N * 2], z[N * 2];
int vis[N], vi[N];
bool ok;

int bfs(int u) {
    vector<int> d(n + 1);queue<int> q;
    q.push(u);vis[u] = 1;d[u] = 0;
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (auto [x, y] : g[t]) {
            if (vis[x]) {
                if (y == 1 && d[x] == d[t]) {
                    ok = true;
                    return -1;
                } else if (y == 0 && d[x] != d[t]) {
                    ok = true;
                    return -1;
                }
            } else {
                if (y == 1) d[x] = d[t] ^ 1;
                else d[x] = d[t];
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) sum += d[i];
    return sum;
}

int bfs1(int u) {
    vector<int> d(n + 1);queue<int> q;
    q.push(u);vi[u] = 1;d[u] = 1;
    while (q.size()) {
        auto t = q.front();q.pop();
        for (auto [x, y] : g[t]) {
            if (vi[x]) {
                if (y == 1 && d[x] == d[t]) {
                    ok = true;
                    return -1;
                } else if (y == 0 && d[x] != d[t]) {
                    ok = true;
                    return -1;
                }
            } else {
                if (y == 1) d[x] = d[t] ^ 1;
                else d[x] = d[t];
                q.push(x);
                vi[x] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) sum += d[i];
    return sum;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        x[i] = u, y[i] = v, z[i] = w;
    }
    if (ok) {
        cout << -1 << '\n';
        return ;
    }
    int ans = 0;
    for (int i = 0; i < 30; i ++) {
        for (int j = 1; j <= n; j ++) g[j].clear();
        for (int j = 1; j <= m; j ++) {
            int u = x[j], v = y[j], w = z[j];
            if (w >> i & 1) {
                g[u].push_back({v, 1});
                g[v].push_back({u, 1});
            } else {
                g[u].push_back({v, 0});
                g[v].push_back({u, 0});
            }
        }
        for (int j = 1; j <= n; j ++) vi[j] = vis[j] = 0;
        for (int j = 1; j <= n; j ++) {
            if (!vis[j]) {
                ans += min(bfs(j), bfs1(j)) * (1ll << i);
                if (ok) {cout << -1 << '\n'; return ;}
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
