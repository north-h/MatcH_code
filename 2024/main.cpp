#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> val(n + 1), deep(n + 1);
    sort(val.begin() + 1, val.end(), [&](int i, int j) {
        return deep[i] < deep[j];
    });
    for (int i = 1; i <= n; i ++) cin >> val[i];
    vector<vector<int>> g(n + 1);
    int idx = 1;
    int ans = 0;
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ans = max(val[u] + val[v], ans);
        mp[idx ++] = {u, v};
    }
    if (n <= 5) {
        cout << accumulate(val.begin() + 1, val.end(), 0) << '\n';
        return ;
    }
    struct tp {int sum, u, v, w;};
    auto check = [&](int a, int b, int c, int d) -> tp {
        if (a == c && b != d) return {val[a] + val[b] + val[d], b, d, a};
        if (a == d && b != c) return {val[a] + val[b] + val[c], b, c, a};
        if (b == c && a != d) return {val[b] + val[a] + val[d], a, d, b};
        if (b == d && a != c) return {val[b] + val[a] + val[c], a, c, b};
        return { -1, -1, -1, -1};
    };
    for (int i = 1; i < idx; i ++) {
        for (int j = i + 1; j <= idx; j ++) {
            auto [ui, vi] = mp[i];
            auto [uj, vj] = mp[j];
            auto [cv, x, y, w] = check(ui, vi, uj, vj);
            if (cv == -1) continue;
            int mx = 0, id = -1;
            for (auto k : g[x]) {
                if ( k == x || k == y || k == w) continue;
                if (mx < val[k]) {
                    mx = val[k];
                    id = k;
                }
            }
            cv += mx;
            mx = 0;
            for (auto k : g[y]) {
                if (k == x || k == y || k == w || k == id) continue;
                mx = max(mx, val[k]);
            }
            cv += mx;
            ans = max(ans, cv);
        }
    }
    cout << ans << '\n';
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