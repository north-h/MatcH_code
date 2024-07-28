// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> t(n + 1);
    int ans = INF;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1, x; j <= m; j ++) {
            cin >> x;
            t[i].push_back(x);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(5010));
    dp[0][0] = 1;
    int target; cin >> target;
    for (int i = 1; i <= n; i ++) {
        for (auto j : t[i]) {
            for (int k = j; k <= 5010; k ++) {
                dp[i][k] |= dp[i - 1][k - j];
            }
        }
    }
    for (int i = 0; i < 5010; i ++) {
        if (dp[n][i]) ans = min(ans, abs(target - i));
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