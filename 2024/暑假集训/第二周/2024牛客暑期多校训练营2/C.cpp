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
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    vector<array<int, 2>> dp(n + 1);
    int ans = 0;
    if (s1[0] == s2[0] && s1[0] == 'R') {
        dp[0][0] = dp[0][1] = 1, ans = 1;
    }
    for (int i = 1; i < s1.size(); i++) {
        if (s1[i] == 'R' && s1[i - 1] == 'R') {
            dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0]);
        }
        if (s2[i] == 'R' && s2[i - 1] == 'R') {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
        }
        if (s1[i] == s2[i] && s1[i] == 'R') {
            int t0 = dp[i][0], t1 = dp[i][1];
            dp[i][0] = max(dp[i][0], t1 + 1);
            dp[i][1] = max(dp[i][1], t0 + 1);
        }
        ans = max(ans, max(dp[i][1], dp[i][0]));
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