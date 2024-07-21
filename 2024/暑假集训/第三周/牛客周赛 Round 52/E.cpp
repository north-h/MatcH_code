// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    bool same(int x, int y) {
        int px = find(x);
        int py = find(y);
        return px == py;
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
            sz[py] += sz[px];
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> val[i];
    }
    vector<int> vis(n + 1);
    DSU dsu(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        dsu.merge(u, v);
        vis[u] = 1;
        vis[v] = 1;
    }
    vector<int> t;
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) {
            int pi = dsu.find(i);
            mp[pi] = max(mp[pi], val[i]);
        } else t.push_back(val[i]);
    }
    for (auto [x, y] : mp) {
        t.push_back(y);
    }
    int ans = 0;
    sort(t.begin(), t.end());
    for (int i = 1; i < t.size(); i ++) {
        ans += t[i];
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