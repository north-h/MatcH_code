// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<vector<int>> g, dis;
int n, m;

vector<int> bfs(int node) {
    queue<int> q;
    vector<int> vis(n + 1), d(n + 1);
    q.push(node);
    vis[node] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (vis[i]) continue;
            d[i] = d[t] + 1;
            q.push(i);
            vis[i] = 1;
        }
    }
    return d;
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int, int> mp[n + 1];
    for (int i = 1; i <= n; i ++) {
        auto t = bfs(i);
        for (int j = 1; j < t.size(); j ++) {
            dis[i].push_back(t[j]);
        }
    }
    string s;
    for (int i = 1; i <= n; i ++) s += '1';
    int k; cin >> k;
    vector<int> p(k + 1), d(k + 1);
    for (int i = 1; i <= k; i ++) {
        cin >> p[i] >> d[i];
        for (int j = 1; j <= n; j ++) {
            if (dis[p[i]][j - 1] < d[i]) s[j - 1] = '0';
        }
    }
    for (int i = 1; i <= k; i ++) {
        int dt = INF;
        for (int j = 1; j <= n; j ++) {
            if (s[j - 1] == '0') continue;
            dt = min(dt, dis[p[i]][j - 1]);
        }
        if (dt == INF || dt != d[i]) {
            cout << "No" << '\n';
            return ;
        }
    }
    cout << "Yes" << '\n';
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}