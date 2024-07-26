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
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    sort(s.begin() + 1, s.end(), [&](string a, string b) {
        return a + b < b + a;
    });
    vector<vector<string>> dp(n + 2, vector<string>(n + 2));
    dp[n][1] = s[n];
    for (int i = n - 1; i >= 1; i --) {
        for (int j = 1; j <= n - i + 1; j ++) {
            dp[i][j] = s[i] + dp[i + 1][j - 1];
            if (dp[i + 1][j] != "") dp[i][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[1][k] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}