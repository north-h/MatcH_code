/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-07 12:07:11
 *
 * Problem: E. Infected Tree
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548070/problem/E
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> deep(n + 10), fa(n + 10, -1);
    vector<vector<int>> g(n + 10);
    for (int i = 1; i < n; i ++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        fa[b] = a;
    }
    int root = 1;
    while (fa[root] != -1) root ++;
    auto dfs = [&](auto dfs, int u, int f) -> void {
        if (g[u].size() == 1) {
            deep[u] = 1;
            return ;
        }
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u);
            deep[u] += deep[v];
        }
    };
    dfs(dfs, root, -1);
    int ans = 1, ok = 0;
    auto dfs1 = [&](auto dfs1, int u, int f) -> void {
        if (ok) return ;
        vector<int> t;
        for (auto v : g[u]) {
            if (v == f) continue;
            t.push_back(v);
        }
        if (!t.size()) return ;
        if (t.size() == 1) {
            ans ++;
            ok = 1;
            return ;
        } else {
            if (deep[t[0]] > deep[t[1]]) {
                dfs1(dfs1, t[1], u);
            } else {
                dfs1(dfs1, t[0], u);
            }
            ans += 2;
        }
    };
    dfs1(dfs1, root, -1);
    cout << n - ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}