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
const int mod = 1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<array<ll,2>> dp(n + 1);
    auto dfs = [&](auto dfs, int u, int f) -> void {
        dp[u][1] = dp[u][0] = 1;
        for (auto i : g[u]) {
            if (i == f) continue;
            dfs(dfs, i, u);
            dp[u][0] = dp[u][0] * dp[i][1] % mod;
            dp[u][1] = dp[u][1] * (dp[i][0] + dp[i][1]) % mod;
        }
    };
    dfs(dfs, 1, -1);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}