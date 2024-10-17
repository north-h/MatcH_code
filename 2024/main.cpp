// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 18, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> dp(1 << N);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i ++) {
        vector<int> mp(19);
        int st = 0, cnt = 0;
        for (int j = i; j < n; j ++) {
            mp[a[j]] ++;
            if (mp[a[j]] > 1) break;
            st ^= (1 << (a[j] - 1));
            cnt ++;
        }
        dp[st] = cnt;
    }
    for (int i = 0; i < 1 << N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i >> j & 1) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << N; i ++) {
        ans = max(ans, dp[i] + dp[i ^ ((1 << N) - 1)]);
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