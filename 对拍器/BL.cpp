// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], vis[N], d[N], son[N];
vector<int> g[N];
int ans, n;


void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (vis[son[t]]) continue;
        d[son[t]] --;
        if (d[t] == 1) {
            q.push(son[t]);
            vis[son[t]] = 1;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> son[i];
        g[son[i]].push_back(i);
        d[i] ++;
        d[son[i]] ++;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ":";
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    topsort();
    vector<int> vi(n + 1);
    int idx = 1;
    map<int, vector<int>> mp;
    auto dfs = [&](auto && dfs, int u) -> void {
        if (vi[u]) return ;
        vi[u] = 1;
        mp[idx].push_back(u);
        // debug2(u, son[u]);
        dfs(dfs, son[u]);
    };
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 2 && !vi[i]) {
            // debug1(i);
            dfs(dfs, i);
            idx ++;
        }
    }
    // cout << "------------" << '\n';
    // for (auto [x, y] : mp) {
    //     cout << x << ':';
    //     for (auto j : y) cout << j << ' ';
    //     cout << '\n';
    // }
    int cnt = 0;
    auto dfs1 = [&](auto && dfs1, int u, int d) -> void {
        // debug2(u, g[u].size());
        // debug1(d);
        if (!g[u].size()) {
            cnt = d;
            return ;
        }
        for (auto v : g[u]) {
            if (vi[v]) continue;
            dfs1(dfs1, v, d + 1);
        }
        // cnt = max(cnt, d);
    };
    int ans = 0;
    for (auto [x, y] : mp) {
        int lian = 0;
        for (auto j : y) {
            cnt = 0;
            // debug1(j);
            dfs1(dfs1, j, 0);
            lian = max(lian, cnt);
        }
        // debug2(huan, lian);
        ans = max(ans, (int)y.size() + lian);
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