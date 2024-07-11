// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int g[11][11];

void solve() {
    int n, m; cin >> n >> m;
    // map<array<int, 2>, int> sz;
    vector<vector<int>> dp(11, vector<int> (11, INF));
    for (int i = 0; i <= 9; i ++) {
        for (int j = 0; j <= 9; j ++) {
            cin >> dp[i][j];
            // sz[ {i, j}] = min(sz[ {i, j}], g[i][j]);
        }
    }
    for (int k = 0; k < 10; k ++) {
        for (int i = 0; i < 10; i ++) {
            for (int j = 0; j < 10; j ++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int x; cin >> x;
            if (x != -1 && x != 1) ans += dp[x][1];
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