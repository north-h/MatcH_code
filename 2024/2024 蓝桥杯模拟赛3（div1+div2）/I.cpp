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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int sum = 0;
    vector<int> num(n + 1);
    vector<int> ve, vis(n + 1);
    int s, e;
    cin >> s >> e;
    auto dfs = [&] (auto dfs, int u, int f) -> void {
        // debug1(u);
        if (u == e) {
            sum ++;
            for (auto i : ve) num[i] ++;
            return ;
        }
        for (auto i : g[u]) {
            if (vis[i]) continue;
            ve.push_back(i);
            vis[i] = 1;
            dfs(dfs, i, u);
            vis[i] = 0;
            ve.pop_back();
        }
    };
    dfs(dfs, s, -1);
    if (sum == 0) cout << -1 << endl;
    else {
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans += (num[i] == sum);
        }
        cout << ans - 1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}