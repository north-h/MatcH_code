// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<vector<array<int, 3>>> g;
int n, m, k;

int dijkstra(int s, int e, int op) {
    vector<int> vis(n + 1), dis(n + 1, 1e15);
    priority_queue < array<int, 2>, vector<array<int, 2>>, greater<>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        if (vis[t[1]]) continue;
        vis[t[1]] = 1;
        for (auto [v, w, d] : g[t[1]]) {
            if (dis[v] > dis[t[1]] + w && (d == 1 || op == 1)) {
                dis[v] = dis[t[1]] + w;
                q.push({dis[v], v});
            }
        }
    }
    return dis[e];
}

void solve() {
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (int i = 1; i <= m; i ++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }
    int ans = 1e15;
    ans = dijkstra(1, n, 0);
    ans = min(dijkstra(1, k, 0) + dijkstra(k, n, 1), ans);
    if (ans == 1e15) ans = -1;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}