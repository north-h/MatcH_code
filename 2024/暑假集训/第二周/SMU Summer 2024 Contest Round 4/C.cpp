// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n + 1), c(n + 1);
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) cin >> c[i];
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        vector<int> T(1);
        int root = i, len = 0;
        while (!vis[root]) {
            T.push_back(c[root]);
            len ++;
            vis[root] = 1;
            root = p[root];
        }
        for (int i = 1; i <= len; i ++) T.push_back(T[i]);
        for (int i = 1; i < T.size(); i ++) T[i] += T[i - 1];
        int v1 = k / len, v2 = k % len, cv = LLONG_MIN;
        auto get = [&](int m, int op) -> int {
            int cc = 0;
            if (op == 1) cc = LLONG_MIN;
            for (int l = 1; l <= m; l ++) {
                for (int j = 1; j + l - 1 < T.size(); j ++) {
                    cc = max(cc, T[j + l - 1] - T[j - 1]);
                }
            }
            return cc;
        };
        if (T[len] > 0) {
            if (v2 == 0) ans = max(ans, (v1 - 1) * T[len] + get(len, 0));
            else ans = max(ans, v1 * T[len] + get(v2, 0));
        } else {
            if (v1 == 0) ans = max(get(k, 1), ans);
            else ans = max(get(len, 1), ans);
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