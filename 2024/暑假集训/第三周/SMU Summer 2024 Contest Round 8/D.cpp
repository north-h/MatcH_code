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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 10>> dp(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < 10; j ++) {
            dp[i][(j + a[i]) % 10] += dp[i - 1][j];
            dp[i][(j + a[i]) % 10] %= mod;
            dp[i][j * a[i] % 10] += dp[i - 1][j];
            dp[i][(j * a[i]) % 10] %= mod;
        }
    }
    for (int i = 0; i < 10; i ++) cout << dp[n][i] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}