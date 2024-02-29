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
    cin >> n >> m >> k;
    vector<int> w(m + 1), v(m + 1), dp(m + 1, INF);
    for (int i = 1; i <= m; i ++) cin >> w[i] >> v[i];
    int p = n - k;

    for (int i = 1; i <= m; i ++) {
        for (int j = p;j <= 30 ; j += n) {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[23] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}