#include<bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << '\n'
#define debug2(a, b) cout << #a << '=' << a << #b << '=' << b << '\n'
#define int long long

using namespace std;

struct S {
    int t, d, w;
};

void solve() {
    int n; cin >> n;
    vector<S> w(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> w[i].t >> w[i].d >> w[i].w;
        mx = max(mx, w[i].d);
    }
    sort(w.begin() + 1, w.end(), [&](S a, S b){
        return a.d < b.d;
    });
    vector<int> dp(mx + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = min(mx, w[i].d); j >= w[i].t; j --) {
            dp[j] = max(dp[j - w[i].t] + w[i].w, dp[j]);
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

