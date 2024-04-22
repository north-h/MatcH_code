// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
// #define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

int n;
int dp[510][510];

void solve() {
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        dp[i][i] = 1;
        dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
    }
    for (int len = 3; len <= n ; len ++) {
        for (int i = 1; i + len - 1 <= n; i ++){
            int l = i, r = i + len - 1;
            if (a[l] == a[r]) dp[l][r] = min (dp[l + 1][r - 1], dp[l][r]);
            for (int k = l; k < r; k ++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    // debug1(dp[2][3]);
    cout << dp[1][n] << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}