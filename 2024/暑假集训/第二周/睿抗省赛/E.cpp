#include<bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << '\n'
#define debug2(a, b) cout << #a << '=' << a << #b << '=' << b << '\n'
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> t(n + 1), d(n + 1), w(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> t[i] >> d[i] >> w[i];
        mx = max(mx, d[i]);
    }
    vector<int> dp(mx + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = min(mx, d[i]); j >= t[i]; j --) {
            dp[j] = max(dp[j - t[i]] + w[i], dp[j]);
            ans = max(dp[j], ans);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}

