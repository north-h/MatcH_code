/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-05 17:49:36
 *
 * Problem: D. Sakurako's Hobby
 * Contest: Codeforces - Codeforces Round 970 (Div. 3)
 * URL:     https://codeforces.com/contest/2008/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    DSU dsu(n + 1);
    string s; cin >> s; s = " " + s;
    vector<int> vis(n + 1), ans(n + 1);
    auto dfs = [&](auto dfs, int x) -> void {
        dsu.merge(x, a[x]);
        if (vis[x]) return ;
        vis[x] = 1;
        dfs(dfs, a[x]);
    };
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) dfs(dfs, i);
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == '0') mp[dsu.find(i)] ++;
    }
    for (int i = 1; i <= n; i ++) {
        cout << mp[dsu.find(i)] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}