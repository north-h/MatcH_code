/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-30 22:37:31
 *
 * Problem: B. Make Three Regions
 * Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1997/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

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

void solve() {
    int n; cin >> n;
    vector<vector<char>> s(3, vector<char>(n + 1));
    for (int i = 1; i <= 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> s[i][j];
        }
    }
    vector<vector<int>> vis(3, vector<int>(n + 2));
    vector<array<int, 2>> zb;
    auto dfs = [&](auto && dfs, int x, int y) -> void {
        vis[x][y] = 1;
        zb.push_back({x, y});
        for (int i = 0; i < 4; i ++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && ty >= 1 && tx <= 2 && ty <= n && !vis[tx][ty]) {
                dfs(dfs, tx, ty);
            }
        }
    };
    int cnt = 0;
    for (int i = 1; i <= 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!vis[i][j] && s[i][j] == '.') {
                dfs(dfs, i, j);
                cnt ++;
            }
        }
    }
    // debug1(cnt);
    int ans = 0;
    if (cnt == 0) {
        cout << 0 << '\n';
        return ;
    }
    for (auto [x, y] : zb) {
        if (y > 1 && y < n ) {
            if (x == 1) {
                if (s[x + 1][y - 1] == 'x' && s[x + 1][y + 1] == 'x' && s[x][y + 1] != 'x' && s[x][y - 1] != 'x' && s[x][y] == '.' && s[x + 1][y] == '.') ans ++;
            } else {
                if (s[x - 1][y - 1] == 'x' && s[x - 1][y + 1] == 'x' && s[x][y + 1] != 'x' && s[x][y - 1] != 'x' && s[x][y] == '.' && s[x - 1][y] == '.') ans ++;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}