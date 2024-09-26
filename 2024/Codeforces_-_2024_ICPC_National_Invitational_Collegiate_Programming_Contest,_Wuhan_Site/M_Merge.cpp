/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-26 18:29:09
 *
 * Problem: M. Merge
 * Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
 * URL:     https://codeforces.com/gym/105143/problem/M
 * MemoryL: 1024 MB
 * TimeL:   4000 ms
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
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] ++;
    sort(a.begin() + 1, a.end());
    map<int, int> vis;
    auto dfs = [&](auto dfs, int x) -> bool {
        // cout << x << '\n';
        if (mp[x]) {
            vis[x] ++;
            return true;
        }
        if (x % 2 == 0 || x == 1) return false;
        bool ok = dfs(dfs, x / 2);
        // cout << "----------" << '\n';
        ok &= dfs(dfs, (x + 1) / 2);
        return ok;
    };
    vector<int> ans;
    for (int i = n; i >= 1; i --) {
        if (mp[a[i]] == 0) continue;
        // for (auto [x, y] : mp) cout << x << ' ' << y << '\n';
        // cout << '\n';
        if (dfs(dfs, a[i] * 2 + 1)) {
            // cout << "--------" << '\n';
            // for (auto [x, y] : vis) debug2(x, y);
            ans.push_back(a[i] * 2 + 1);
            for (auto [x, y] : vis) mp[x] -= y;
        }
        // cout << "-++-\n";
        vis.clear();
        if (dfs(dfs, a[i] * 2 - 1)) {
            // return ;
            // cout << "--------" << '\n';
            // for (auto [x, y] : vis) debug2(x, y);
            ans.push_back(a[i] * 2 - 1);
            for (auto [x, y] : vis) mp[x] -= y;
        }
        vis.clear();
    }
    for (int i = 1; i <= n; i ++) {
        if (mp[i]) ans.push_back(a[i]);
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}