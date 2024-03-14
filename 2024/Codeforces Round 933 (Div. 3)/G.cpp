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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    map<PII, int> color;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        color[{a, b}] = c;
        color[{b, a}] = c;
    }
    int s, e;
    cin >> s >> e;
    vector<int> vis(n + 1);
    set<int> st;
    int ans = INF;
    auto dfs = [&] (auto self, int u, int f, int d)->void {
        if (u == e) {
            ans = min(ans, d);
            return ;
        }
        // int op = -1;
        vis[u] = 1;
        // for (auto i : g[u]) {
        //     if (i == f) {
        //         op = color[{u, f}];
        //         op = color[{f, u}];
        //     }
        // }
        for (auto i : g[u]) {
            if (u == s) {
                self(self, i, u, d + 1);
            }
            if (vis[i] || i == f) continue;
            int o = color[{i, u}];
            o = color[{u, i}];
            if (st.count(o)) {
                self(self, i, u, d);
            } else {
                st.insert(o);
                self(self, i, u, d + 1);
                st.erase(o);
            }
        }
    };
    dfs(dfs, s, 0, 0);
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