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
    int n;
    cin >> n;
    vector<vector<int>> g (n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n ; i ++) {
        int k;
        cin >> k;
        for (int j = 1, x; j <= k; j ++) {
            cin >> x;
            mp[x] = 1;
            g[i].push_back(x);
        }
    }
    vector<int> vis(n + 1), dis(n + 1);
    int ans = 0, sum = 0;
    auto dfs = [&](auto dfs, int u) -> void {
        vis[u] = 1;
        for (auto i : g[u]) {
            if (vis[i]) continue;
            dis[i] = max(dis[u] + 1, dis[i]);
            dfs(dfs, i);
        }
    };
    int s = 1;
    while (mp[s]) s ++;
    dis[s] = 0;
    dfs(dfs, s);
    for (int i = 1; i <= n; i ++) {
        if (sum < dis[i]) {
            sum = dis[i];
            ans = i;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}