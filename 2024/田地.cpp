// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) {
        fa.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    bool same(int x, int y) {
        int px = find(x);
        int py = find(y);
        return px == py;
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
            sz[py] += sz[px];
        }
    }
};



void solve() {
    int n; cin >> n;
    DSU dsu(n + 1);
    vector<int> a(n + 1), b(n + 2, -1), vis(n + 3);
    for (int i = 1; i <= n; i ++) cin >> dsu.sz[i];
    map<int, int> mp;
    for (int j = 1; j <= n; j ++) cin >> b[j];
    // for (int i = 1; i <= n; i ++) cout << dsu.sz[i] << '\n';
    vector<int> ans;
    int sum = 0;
    for (int i = n ; i >= 1; i --) {
        // debug2(sum, mp[i]);
        vis[b[i]] = 1;
        if (vis[b[i] + 1]) {
            dsu.merge(b[i], b[i] + 1);
        }
        if (vis[b[i] - 1]) {
            dsu.merge(b[i], b[i] - 1);
        }
        ans.push_back(sum);
        sum = max(sum, dsu.sz[dsu.find(b[i])]);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << '\n';
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