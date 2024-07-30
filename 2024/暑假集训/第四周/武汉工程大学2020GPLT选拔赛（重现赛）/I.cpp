// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, w; cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = n;
    vector<int> cc(n + 1);
    auto dfs = [&](auto && dfs, int u, int cnt) -> void {
        if (cnt >= ans) return ;
        if (u == n) {
            ans = min(cnt + 1, ans);
            return ;
        }
        for (int i = 0; i <= cnt; i ++) {
            if (cc[i] + a[u] <= w) {
                cc[i] += a[u];
                dfs(dfs, u + 1, cnt);
                cc[i] -= a[u];
            }
        }
        cc[cnt + 1] += a[u];
        dfs(dfs, u + 1, cnt + 1);
        cc[cnt + 1] -= a[u];
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}