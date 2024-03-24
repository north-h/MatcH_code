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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;int c = 0;
        auto dfs = [&](auto self, int u, int f) -> int{
            int res = 1;
            for (auto i : g[u]) {
                if (i == f) continue;
                res += self(self, i, u);
            }
            if (res >= mid) {
                c ++;
                return 0;
            }
            return res;
        };
        dfs(dfs, 1, 0);
        if (c - 1 >= k) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
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