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

int dp[55][55][15][15], g[55][55];

void solve() {
    int  n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    auto dfs = [&](auto dfs, int x, int y, int c, int v) -> void {
        if (x == n && y == m) {
            if (c == k) ans ++;
            if (v < g[x][y] && c +1 ==k) ans ++;
        }
        //选
        if (v < g[x][y] && c < k) {
            if (x + 1 <= n) dfs(dfs, x + 1, y, c + 1, g[x][y]);
            if (y + 1 <= m) dfs(dfs, x, y + 1, c + 1, g[x][y]);
        }

        //不选
        if (x + 1 <= n) dfs(dfs, x + 1, y, c, v);
        if (y + 1 <= m) dfs(dfs, x, y + 1, c, v);
    };
    dfs(dfs, 1, 1, 0, -1);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}