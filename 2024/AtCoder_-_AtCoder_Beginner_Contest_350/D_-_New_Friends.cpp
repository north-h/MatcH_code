/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-20 20:27:10 ms
 *
 * Problem: D - New Friends
 * Contest: AtCoder - AtCoder Beginner Contest 350
 * URL:     https://atcoder.jp/contests/abc350/tasks/abc350_d
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

struct DSU {
    vector<int> fa;
 
    DSU(int n) {
        fa.resize(n + 1);
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
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU d(n + 1);
    vector<int> dg(n + 1);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        d.merge(x, y);
        dg[x] ++;
        dg[y] ++;
    }
    if (m == 0) {
        cout << 0 << '\n';
        return ;
    }
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++) {
        mp[d.find(i)].push_back(dg[i]);
    }
    int ans = 0;
    for (auto [x, y] : mp) {
        for (auto j : y) {
            ans += y.size() - 1 - j;
        }
    }
    cout << ans / 2 << '\n';
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