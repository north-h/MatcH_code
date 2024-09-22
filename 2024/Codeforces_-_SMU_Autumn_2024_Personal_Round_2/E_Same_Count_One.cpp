/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 15:09:19
 *
 * Problem: E. Same Count One
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/E
 * MemoryL: 512 MB
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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    map<int, int> mp, up;
    int sum;
    for (int i = 1; i <= n; i ++) {
        int cnt = 0;
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 1) cnt ++;
        }
        mp[i] = cnt;
        sum += cnt;
    }
    map<int, vector<int>> pp;
    for (int j = 1; j <= m; j ++) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (g[i][j] == 1) {
                cnt ++;
                pp[j].push_back(i);
            }
        }
        up[j] = cnt;
    }
    if (sum % n) {
        cout << -1 << '\n';
        return ;
    }
    map<int, int> T;
    vector<array<int, 3>> ans;
    int st = 1;
    for (int j = 1; j <= m; j ++) {
        int ss = st;
        for (auto i : pp[j]) {
            ans.push_back({ss, i, j});
            T[ss] ++;
        }
        while (T[st])
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}