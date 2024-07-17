// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<int> g[N];
int match[N], vis[N], ans;

bool dfs(int u) {
    for (auto v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int k; cin >> k;
        for (int j = 1, x; j <= k; j ++) {
            cin >> x;
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) vis[j] = 0;
        if (dfs(i)) ans ++;
    }
    if (ans == n) cout << "Yes" << '\n';
    else cout << "No" << '\n' << n - ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}