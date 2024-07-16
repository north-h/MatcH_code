// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
#define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n + 1), c(n + 1);
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
        ans = max(ans, c[i]);
    }
    vector<int> vis(n + 1);
    map<int, vector<int>> mp;
    int idx = 1;
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        int j = i;
        mp[idx].push_back(0);
        while (!vis[j]) {
            vis[j] = 1;
            j = p[j];
            mp[idx].push_back(c[j]);
        }
        idx ++;
    }
    // for (auto &[x, y] : mp) {
    //     cout << x << ':';
    //     for (auto j : y) cout << j << ' ';
    //     cout << '\n';
    // }
    map<int, int> up;
    for (auto &[x, y] : mp) {
        // cout << x << ':';
        int m = y.size();
        up[x] = y.size() - 1;
        for (int j = 1; j < m; j ++) y.push_back(y[j]);
        for (int j = 1; j < y.size(); j ++) y[j] += y[j - 1];
        // for (auto j : y) cout << j << ' ';
        // cout << '\n';
    }
    for (auto [x, y] : mp) {
        int m = y.size();
        int mn = up[x];
        for (int len = 1; len <= min(mn - 1, k); len ++) {
            for (int j = 1; j + len - 1 < y.size(); j ++) {
                int val = y[j + len - 1] - y[j - 1];
                ans = max(val, ans);
            }
        }
        // debug2(ans, mn);
        if (k >= mn) {
            int c1 = y[mn], c2 = LLONG_MIN;
            int v1 = k / mn, v2 = k % mn;
            for (int j = 1; j + v2 - 1 < y.size(); j ++) {
                c2 = max(c2, y[j + v2 - 1] - y[j - 1]);
            }
            int T = 0;
            for (int len = 1; len <= mn; len ++) {
                for (int j = 1; j + len - 1 < y.size(); j ++) {
                    int vl = y[j + len - 1] - y[j - 1];
                    int vi = y[mn] - vl;
                    // debug2(vi, vl);
                    T = max(T, max(vi, vl));
                }
            }
            // debug2(c1, c2);
            // debug2(v1, v2);
            // debug1(T);
            int res;
            if (c2 == 0 && v1 > 1) res = c1 * (v1 - 1) + T;
            else res = c1 * v1 + c2;
            ans = max(ans, res);
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