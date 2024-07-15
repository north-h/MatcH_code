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
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 0; i < n; i ++) {
        a[i + 1] = (s[i] - '0');
    }
    // cout << '\n';
    vector<int> dp(210, -20);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 200; j >= a[i]; j --) {
            if (dp[j - a[i]] == -20) continue;
            dp[j] = max(dp[j], dp[j - a[i]] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 200; i ++) {
        if (i % 3 || dp[i] == -20) continue;
        ans = max(ans, dp[i]);
    }
    if (ans == 0) cout << -1 << '\n';
    else cout << n - ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}