// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> dp(n + 1, INF), a(n + 1), t(n + 1);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) cin >> t[i];
    for (int i = 1; i <= k; i ++) dp[a[i]] = t[i];
    for (int i = 2; i <= n; i ++) dp[i] = min(dp[i], dp[i - 1] + 1);
    for (int i = n - 1; i >= 1; i --) dp[i] = min(dp[i], dp[i + 1] + 1);
    for (int i = 1; i <= n; i ++) cout << dp[i] << " \n"[i == n];
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}