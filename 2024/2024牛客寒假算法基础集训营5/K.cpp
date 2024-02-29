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
    int n, p;
    cin >> n >> p;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }
    w.push_back(1);
    v.push_back(p);
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i ++) {
        for (int j = 0; j <= n - 1;j ++) {
            dp[j] = min(dp[j], dp[max(0, j - w[i])] + v[i]);
        }
    }
    cout << dp[n - 1] + p << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}