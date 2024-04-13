/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:44 ms
 *
 * Problem: P8710 [蓝桥杯 2020 省 AB1] 网络分析
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8710?contestId=166591
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

struct DSU {
    vector<int> fa, sz;
 
    DSU(int n) {
        fa.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
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
            sz[py] += sz[x];
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    vector<int> sum(n + 1);
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            dsu.merge(a, b);
        } else {
            int p, t; cin >> p >> t;
            int pp = dsu.find(p);
            for (int i = 1; i<= n; i ++) {
                if (dsu.find(i) == pp) sum[i] += t;
            }
        }
    }
    for (int i = 1; i <= n; i ++) cout << sum[i] << " \n"[i == n];
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