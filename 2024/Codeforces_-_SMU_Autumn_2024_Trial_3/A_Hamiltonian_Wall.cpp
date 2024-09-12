/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-12 19:18:09
 *
 * Problem: A. Hamiltonian Wall
 * Contest: Codeforces - SMU Autumn 2024 Trial 3
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549249/problem/A
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

void solve() {
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int bc = 0;
    for (int i = 0; i <= 1; i ++) {
        for (auto j : s[i]) bc += (j == 'B');
    }
    // debug1(bc);
    bool ok = false;
    vector vis(2, vector<int>(n + 1));
    auto dfs = [&](auto dfs, int x, int y, int cnt) -> void {
        vis[x][y] = 1;
        if (bc == cnt) ok = true;
        if (ok) return ;
        // debug2(x, y);
        if (s[x ^ 1][y] == 'B' && !vis[x ^ 1][y]) dfs(dfs, x ^ 1, y, cnt + 1);
        else if (!vis[x][y + 1] && s[x][y + 1] == 'B') dfs(dfs, x, y + 1, cnt + 1);
    };
    if (s[0][0] == 'B') dfs(dfs, 0, 0, 1);
    // debug1(ok);
    vector<vector<int>> (2, vector<int> (n + 1)).swap(vis);
    if (s[1][0] == 'B') dfs(dfs, 1, 0, 1);
    // debug1(ok);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}