// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, mod = 1e9 + 7;

using namespace std;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector g(n + 1, vector<int>());
    for (int i = 1; i < n; i ++) {
        int l, r; cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    int ans = 0;
    auto dfs = [&](auto dfs, int u, int f, int cv, int cc) -> void {
        int cnt = g[u].size();
        if (u != 1) cnt --;
        // debug2(cnt, u);
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u, cv + 1, cc * ksm(cnt, mod - 2) % mod);
        }
        if (cnt == 0) {
            ans += (cv * cc % mod), ans %= mod;
        }
    };
    dfs(dfs, 1, 0, 1, 1);
    cout << ans % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}