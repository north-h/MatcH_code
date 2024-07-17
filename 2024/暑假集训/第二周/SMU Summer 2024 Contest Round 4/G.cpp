// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 3010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, mod;
int dp[N][N][2];

void solve() {
    cin >> n >> mod;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;

    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            dp[i + 1][j][1] += dp[i][j][0];
            dp[i + 1][j][1] %= mod;
            dp[i + 1][j + 1][0] += dp[i][j][0];
            dp[i + 1][j + 1][0] %= mod;


            dp[i + 1][j][1] += dp[i][j][1];
            dp[i + 1][j][1] %= mod;
            dp[i + 1][j + 1][1] += dp[i][j][1] * 3ll;
            dp[i + 1][j + 1][1] %= mod;
            dp[i + 1][j + 2][0] += dp[i][j][1] * 2;
            dp[i + 1][j + 2][0] %= mod;
        }
    }
    for (int j = 1; j < n; j++) {
        cout << dp[n][j][1] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}