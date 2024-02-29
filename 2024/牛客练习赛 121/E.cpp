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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n;
    vector<int> sp(n + 1);
    for (int i = 1; i <=n; i ++) cin >> sp[i];
    sort(sp.begin() + 1, sp.end(), greater<int>());
    cin >> m;
    vector<int> zk(m + 1);
    for (int i = 1; i <= m; i ++) cin >> zk[i];
    sort(zk.begin() + 1, zk.end());
    cin >> k;
    vector<int> lj(k + 1);
    for (int i = 1; i <= k; i ++) cin >> lj[i];
    sort(lj.begin() + 1, lj.end(), greater<int>());
    vector<vector<double>> dp (n + 1, vector<double>(m + 1, 0));
    int p = min(n, m + k);
    for (int i = 1; i <= p; i ++) {
        for (int j = 0; j <= min(i, m); j ++) {
            if (j > 0) dp[i][j] = dp[i - 1][j - 1] + sp[i] * zk[j] * 0.01;
            else dp[i][j] = dp[i - 1][j] + sp[i];
            if (i - j <= k && i - j >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + max(0, sp[i] - lj[i - j]));
        }
    }
    double ans = INF;
    for (int i = 0; i <= m; i ++) ans = min(ans, dp[p][i]);
    for (int i = p + 1; i <= n; i ++) ans += sp[i];
    cout << lf(6) << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}