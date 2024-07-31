// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(h + 1, INF)));
    dp[1][1][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i == 1 && j == 1) continue;
            for (int k = 0; k <= h; k ++) {
                dp[i][j][k] = min(dp[i - 1][j][k] + 1, dp[i][j][k]);
                dp[i][j][k] = min(dp[i][j - 1][k] + 1, dp[i][j][k]);
                if (k >= g[i][j]) {
                    dp[i][j][k] = min(dp[i - 1][j][k - g[i][j]], dp[i][j][k]);
                    dp[i][j][k] = min(dp[i][j - 1][k - g[i][j]], dp[i][j][k]);
                }
            }
        }
    }
    cout << dp[n][m][h - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}