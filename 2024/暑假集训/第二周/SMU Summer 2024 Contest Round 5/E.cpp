#pragma GCC optimize("Ofast")
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
map<vector<vector<char>>, int> mp;


void solve() {
    int n, k; cin >> n >> k;
    vector<vector<char>> g(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    auto dfs = [&](auto && dfs, int c) -> void {
        // debug1(c);
        if (mp.count(g) || c < 0) return ;
        mp[g] ++;
        if (c == 0) {
            ans ++;
            return ;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (g[i][j] != '.') continue;
                for (int k = 0; k < 4; k ++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 1 || ty < 1 || tx > n || ty > n) continue;
                    if (g[tx][ty] == '#' || g[tx][ty] != 'R') continue;
                    // vis[tx][ty] = 1;
                    g[i][j] = 'R';
                    dfs(dfs, c - 1);
                    // vis[tx][ty] = 0;
                    g[i][j] = '.';
                }

            }
        }
    };
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (g[i][j] == '.') {
                // debug2(i, j);
                g[i][j] = 'R';
                dfs(dfs, k - 1);
                g[i][j] = '.';
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}