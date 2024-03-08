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
#define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

int dp[2010][2010];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) dp[i][i + 1] = (a[i] + a[i + 1]) % 3;
    for (int len = 1; len <= n; len ++) {
        for (int l = 1, r = l + len - 1; r <= n; l ++, r ++) {
            if (l - 2 >= 1) dp[l - 2][r] = max(dp[l - 2][r], dp[l][r] + (a[l - 1] + a[l - 2]) % 3);
            if (r + 2 <= n) dp[l][r + 2] = max(dp[l][r + 2], dp[l][r] + (a[r + 1] + a[r + 2]) % 3);
            if (l - 1 >= 1 && r + 1 <= n) dp[l - 1][r + 1] = max(dp[l- 1][r + 1], dp[l][r] + (a[l - 1] + a[r + 1]) % 3);
        }
    }
    cout << dp[1][n] << endl;
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