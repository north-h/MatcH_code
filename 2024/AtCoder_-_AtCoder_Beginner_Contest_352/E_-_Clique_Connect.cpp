/*
 * ==========================================================
 * Author:  north_h
 * Time:    2024-05-04 20:14:54 ms
 *
 * Problem: E - Clique Connect
 * Contest: AtCoder - AtCoder Beginner Contest 352
 * URL:     https://atcoder.jp/contests/abc352/tasks/abc352_e
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==========================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
#define int long long

using namespace std;
// using ll = long long;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        sz.resize(n + 1, 1);
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
    vector<vector<int>> a(m + 1);
    vector<int> c(m + 1), p(m + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= m; i ++) {
        int k; cin >> k >> c[i];
        a[i].resize(k + 1);
        for (int j = 1; j <= k; j ++) {
            cin >> a[i][j];
        }
    }
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int x, int y) {
        return c[x] < c[y];
    });
    int v = n, ans = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = 2; j < a[p[i]].size(); j ++) {
            if (!dsu.same(a[p[i]][j], a[p[i]][j - 1])) {
                dsu.merge(a[p[i]][j], a[p[i]][j - 1]);
                ans += c[p[i]];
                v --;
            }
        }
    }
    if (v > 1) cout << -1 << '\n';
    else cout << ans << '\n';
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