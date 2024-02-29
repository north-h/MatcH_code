// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int x1, y1, x2, y2;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto &&self, int x, int y) -> void {
        x1 = min(x1, x);
        y1 = min(y1, y);
        x2 = max(x2, x);
        y2 = max(y2, y);
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if (g[xx][yy] == '*')continue;
            if (vis[xx][yy])continue;
            self(self, xx, yy);
        }
    };
    auto check = [&](int x1, int y1, int x2, int y2) -> bool {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (g[i][j] == '*') return false;
            }
        }
        return true;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            x1 = y1 = INF;
            x2 = y2 = 0;
            if (g[i][j] == '.' && !vis[i][j]) {
                dfs(dfs, i, j);
                if (check(x1, y1, x2, y2)) ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}