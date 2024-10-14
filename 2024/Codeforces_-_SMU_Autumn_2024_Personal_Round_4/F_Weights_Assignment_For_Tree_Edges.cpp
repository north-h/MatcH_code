/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 14:54:14
 *
 * Problem: F. Weights Assignment For Tree Edges
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), b(n + 1), ans(n + 1), d(n + 1);
    vector g(n + 1, vector<int>());
    map<int, int> mp;
    int root;
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        if (i == b[i]) {
            root = i;
            continue;
        }
        g[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        mp[p[i]] = i;
    }
    bool ok = false;
    auto dfs = [&](auto dfs, int u) -> void {
        for (auto v : g[u]) {
            if (mp[v] < mp[u]) ok = true;
            dfs(dfs, v);
        }
    };
    dfs(dfs, root);
    if (ok) {
        cout << -1 << '\n';
        return ;
    }
    ans[root] = 0;
    for (int i = 2; i <= n; i ++) {
        ans[p[i]] = ans[p[i - 1]] + 1;
    }
    for (int i = 1; i <= n; i ++) {
        cout << ans[i] - ans[b[i]] << ' ';
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