// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> red(n), blue(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i ++) {
        cin >> red[i][0] >> red[i][1];
    }
    for (int i = 0; i < n; i ++) {
        cin >> blue[i][0] >> blue[i][1];
        for (int j = 0; j < n; j ++) {
            if (red[j][0] < blue[i][0] && red[j][1] < blue[i][1]) {
                g[j].push_back(i);
            }
        }
    }
    vector<int> vis;
    vector<int> match(n, -1);
    auto dfs = [&](auto &&dfs, int  u) -> bool {
        for (auto v : g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            if ((match[v] == -1 || dfs(dfs, match[v]))) {
                match[v] = u;
                return 1;
            }
        }
        return 0;
    };
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        vector<int>(n).swap(vis);
        if (dfs(dfs, i)) ans ++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}