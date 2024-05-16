// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

int n;
int dp[N], a[N];
vector<int> g[N];

void dfs1(int u, int f) {
    for (auto v : g[u]) {
        if (v == f) continue;
        if (a[v] * 2 >= a[u]) dp[v] ++;
        dfs1(v, u);
        dp[u] += dp[v];
    }
}

void dfs2(int u, int f) {
    for (auto v : g[u]) {
        if (v == f) continue;
        dp[v] += dp[u] - dp[v] - 1;
        if (a[u] * 2 >= a[v]) dp[v] ++;
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i ++) cout << dp[i] << " \n"[i == n];
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans += (dp[i] == n - 1);
    cout << ans << '\n';
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