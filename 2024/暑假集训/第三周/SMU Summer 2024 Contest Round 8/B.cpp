// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

void solve() {
    int n, m, V; cin >> n >> m >> V;
    vector<vector<int>> dp(n + 1, vector<int>(V + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = j; k <= V; k ++) {
                dp[i][k] += dp[i - 1][k - j];
                dp[i][k] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = n; i <= V; i ++) {
        ans += dp[n][i];
        ans %= mod;
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