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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    double z, r;
    cin >> n >> z >> r;
    vector<double> gl(n);
    vector<vector<int>> g(n);
    gl[0] = z;
    double ans = 0;
    map<int, int> mp;
    auto dfs = [&](auto dfs, int u, int f) -> void {
        if (g[u].empty()) {
            gl[u] *= mp[u];
            ans += gl[u];
            return ;
        }
        for (auto i : g[u]) {
            if (i == f) continue;
            gl[i] = gl[u] - gl[u] * (r / 100);
            dfs(dfs, i, u);
        }
    };
    vector<int> vis(n + 1);
    auto bfs = [&](int u) -> void {
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (g[t].size() == 0) {
                gl[t] *= mp[t];
                ans += gl[t];
                continue;
            }
            for (auto i : g[t]) {
                if (vis[i]) continue;
                q.push(i);
                vis[i] = 1;
                gl[i] = gl[t] - gl[t] * (r / 100);
            }
        }
    };
    for (int i = 0; i < n ; i ++) {
        int k, x;
        cin >> k;
        if (k == 0) {
            cin >> x;
            mp[i] = x;
        } else {
            while (k --) {
                cin >> x;
                g[i].push_back(x);
            }
        }
    }
    bfs(0);
    // dfs(dfs, 0, -1);
    // for (auto i : gl) cout << i << ' ';
    // cout << endl; 
    cout << (int)ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}