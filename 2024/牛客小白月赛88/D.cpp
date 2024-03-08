// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] %= n;
    }
    vector<vector<int>> dp(m + 1, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j <= n - 1; j ++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][(j + a[i]) % n]);
            dp[i][j] = max(dp[i][j], dp[i - 1][(j - a[i] + n) % n]);
        }
    }
    if (dp[m][0] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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