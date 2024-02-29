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

void solve() {
    int w, b;
    cin >> w >> b;
    vector<vector<double>> dp(w + 1, vector<double>(b + 1));
    // for (int i = 1; i <= w; i ++) {
    //     dp[i][0] = 1;
    //     for (int j = 1; j <= b; j ++) {
    //         dp[i][j] +=  i * 1.0 / (i + j);
    //         if (i >= 1 && j >= 2) dp[i][j] += j * 1.0 / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
    //         if (j >= 3) dp[i][j] +=  j * 1.0 / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
    //     }
    // }
    // cout << lf(9) << dp[w][b] << endl;
    auto dfs = [&](auto dfs, int w, int b) -> double {
        if (w == 0) return 0;
        if (b == 0) return 1;
        if (dp[w][b]) return dp[w][b];
        dp[w][b] = w * 1.0 / (w + b);
        if (w >= 1 && b >= 2) {
            dp[w][b] += b * 1.0 / (w + b) * (b - 1) / (w + b - 1) * w / (w + b - 2) * dfs(dfs, w - 1, b - 2);
        }
        if (b >= 3) {
            dp[w][b] +=  b * 1.0 / (w + b) * (b - 1) / (w + b - 1) * (b - 2) / (w + b - 2) * dfs(dfs, w, b - 3);
        }
        return dp[w][b];
    };
    cout << lf(9) << dfs(dfs, w, b) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}