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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> g(n + 1);
    vector<pair<int, char>> d(m);
    for (int i = 0; i < m; i ++) {
        cin >> d[i].fi >> d[i].se;
    }
    set<int> ans;
    auto dfs = [&] (auto self, int md, int u, int s) -> void {
        if (md == m) {
            if (s == m) ans.insert(u);
            return ;
        }
        int sy = (u + d[md].fi) % n;
        int ny = (u - d[md].fi + n) % n;
        // debug1(s);
        if (ny == 0) ny = n;
        if (sy == 0) sy = n;
        if (d[md].se == '?') {
            self(self, md + 1, sy, s + 1);
            self(self, md + 1, ny, s + 1);
        } else {
            if (d[md].se == '0') self(self, md + 1, sy, s + 1);
            else self(self, md + 1, ny, s + 1);
        }
    };
    dfs(dfs, 0, x, 0);
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
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