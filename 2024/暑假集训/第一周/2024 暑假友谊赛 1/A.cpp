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
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin  >> a[i];
        sum += a[i];
    }
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = sum; j >= a[i]; j --) {
            if (dp[j - a[i]]) dp[j] = 1;
        }
    }
    int ans = INF;
    for (int i = 1; i <= sum; i ++) {
        if (dp[i])   
            ans = min(ans, max(sum - i, i));
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