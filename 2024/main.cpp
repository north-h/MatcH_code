// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int m = 30;
    vector dp(n + 1, vector<int>(m + 1, -1e15));
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= min(i, m); j ++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] / (1 << j)) - k);
            if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i] / (1 << j)));
            ans = max(ans,  dp[i][j]);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}