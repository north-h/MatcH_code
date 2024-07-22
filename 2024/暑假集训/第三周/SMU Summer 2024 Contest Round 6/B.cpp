// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 55;
const int INF = 0x3f3f3f3f;

using namespace std;


int dp[N][N][N * N];

void solve() {
    int n, A; cin >> n >> A;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i ++) dp[i][0][0] = 1, dp[i][0][1] = dp[i][1][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            for (int k = 1; k <= 2500; k ++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= a[i]) dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        ans += dp[n][i][i * A];
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