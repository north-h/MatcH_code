// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct S {
    int u, v, w;
};

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
    int k = 0;
    vector<array<int, 2>> zj;
    map<array<int, 2>, int> id;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == '*') {
                zj.push_back({i, j});
                id[ {i, j}] = k ++;
            }
        }
    }
    vector<S> edge;
    auto bfs = [&](int x, int y) -> void {
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        queue<array<int, 3>> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++) {
                int tx = t[0] + dx[i];
                int ty = t[1] + dy[i];
                if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
                if (vis[tx][ty] || g[tx][ty] == '#') continue;
                q.push({tx, ty, t[2] + 1});
                vis[tx][ty] = 1;
                if (g[tx][ty] == '*')
                    edge.push_back({id[{x, y}], id[{tx, ty}], t[2] + 1});
            }
        }
    };
    for (auto [x, y] : zj) bfs(x, y);
    sort(edge.begin(), edge.end(), [&](S a, S b) {
        return a.w < b.w;
    });
    DSU dsu(k + 1);
    int cnt = 0, ans = 0;
    for (auto [u, v, w] : edge) {
        if (!dsu.same(u, v)) {
            cnt ++;
            ans += w;
            dsu.merge(u, v);
        }
    }
    if (cnt < k - 1) cout << "No" << '\n';
    else cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}