// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 90001000;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;


vector<int> prime;
bool vis[N];
int n;
map<int, int> mp;

<<<<<<< HEAD
void euler() {
    memset(vis, true, sizeof(vis));
    vis[0] = vis[1] = 0;
    for (int i = 2; i <= 1e6; ++i) {
        if (vis[i]) {
            prime.push_back(i);
            mp[i] = prime.size();
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= 1e6; ++j) {
            vis[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

bool get(int x) {
    if (x == 1 || x == 0) return false;
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) return false;
=======
void dfs1(int u, int f) {
    for (auto v : g[u]) {
        if (v == f) continue;
        if (a[v] * 2 >= a[u]) dp[u] ++;
        dfs1(v, u);
        dp[u] += dp[v];
    }
}

void dfs2(int u, int f) {
    for (auto v : g[u]) {
        if (v == f) continue;
        dp[v] += dp[u] - dp[v];
        if (a[v] * 2 >= a[u]) dp[v] --;
        if (a[u] * 2 >= a[v]) dp[v] ++;
        dfs2(v, u);
>>>>>>> 536bce1b73f73748c197242c487aeac11a994e38
    }
    return true;
}

void solve() {
    cin >> n;
<<<<<<< HEAD
    euler();
    for (int i = n; ; i ++) {
        if (vis[i]) {
            for (int j = mp[i]; ; j ++) {
                if (vis[j]) {
                    cout << prime[j - 1];
                    return ;
                }
            }
        }
    }
=======
    for (int i = 1; i <= n; i ++) {
        g[i].clear();
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans += (dp[i] == n - 1);
    cout << ans << '\n';
>>>>>>> 536bce1b73f73748c197242c487aeac11a994e38
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