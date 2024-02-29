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
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1);
    vector<PII> a;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
    }
    int g = s[1];
    for (int i = 1; i <=m; i ++) {
        int u, v;
        cin >> u >> v;
        if (u == 1 || v == 1) {
            g += 3;
            continue;
        }
        a.push_back({u, v});
    }
    int ans = INF;
    auto dfs = [&](auto dfs, int p) -> void {
        if (p == a.size()) {
            int res = 1;
            for (int i = 1; i <= n; i ++) {
                if (s[i] > g) res ++; 
            }
            ans = min(ans, res);
            return ;
        }
        s[a[p].fi] += 3;
        dfs(dfs, p + 1);
        s[a[p].fi] -= 3;

        s[a[p].se] += 3;
        dfs(dfs, p + 1);
        s[a[p].se] -= 3;

        s[a[p].fi] ++;
        s[a[p].se] ++;
        dfs(dfs, p + 1);
        s[a[p].fi] --;
        s[a[p].se] --;
    };
    dfs(dfs, 0);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}