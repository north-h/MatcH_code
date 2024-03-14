// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> s;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        vector<int> dp(m + 1, 0);
        dp[1] = 1;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({1, 1});
        for (int j = 2; j <= m; j ++) {
            while (pq.size() && j - pq.top().se - 1 > d) pq.pop();
            dp[j] = pq.top().fi + a[i][j] + 1;
            pq.push({dp[j], j});
            // debug2(dp[j], j);
        }
        // debug1(dp[m]);
        s.push_back(dp[m]);
    }
    int ans = LLONG_MAX;
    int c = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        if (i <= k - 1) c += s[i];
        else {
            c += s[i];
            c -= s[j];
            j ++;
        }
        if (i >= k - 1) ans = min(ans, c);
    }
    cout << ans << endl;
}
 
int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}