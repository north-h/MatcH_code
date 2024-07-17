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
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
        ans = max(ans, c[i]);
    }
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
        int v1 = k / len, v2 = k % len;
        if (v2 == 0) {
            int cv = LLONG_MIN;
            for (int j = 1; j <= len; j ++) {
                for (int k = 1; k + j - 1 <= len; k ++) {
                    int l = j, r = j + k - 1;
                    cv = max(cv, T[r] - T[l - 1]);
                }
            }
            if (v1 > 1) {
                ans = max(ans, (v1 - 1) * T[len] + max(0ll, cv));
            } else {
                ans = max(ans, cv);
            }
        } else {
            int tv = LLONG_MIN;
            for (int j = 1; j + v2 - 1 < T.size(); j ++) {
                tv = max(tv, T[j + v2 - 1] - T[j - 1]);
            }
            ans = max(ans, tv + T[len] * v1);
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