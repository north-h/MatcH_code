#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
struct S {
    int u, v, w;

};
vector<S> val;
map<array<int, 2>, int> g;
int n, m, q;
int fa[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a, int b) {
    int pa = find(a), pb = find(b);
    fa[pa] = pb;
}

void solve() {
    cin >> n >> m >> q;
    val.resize(m + 1);
    for (int i = 1; i <= m; i ++) {
        int a, b, c; cin >> a >> b >> c;
        val[i] = {a, b, c};
        g[ {a, b}] = c;
        g[ {b, a}] = c;
    }
    sort(val.begin() + 1, val.end(), [&](S a, S b) {
        return a.w < b.w;
    });
    while (q --) {
        int k; cin >> k;
        vector<int> node(k + 1), query(n + 1);
        for (int i = 1; i <= k; i ++) {
            cin >> node[i];
            fa[node[i]] = node[i];
            query[node[i]] = 1;
        }
        vector<S> edge;
        int cnt = 0, sum = 0;
        if (k < 1000) {
            for (int i = 1; i <= k; i ++) {
                for (int j = i + 1; j <= k; j ++) {
                    if (i == j) continue;
                    int u = node[i], v = node[j];
                    if (g.count({u, v})) {
                        edge.push_back({u, v, g[{u, v}]});
                    }
                }
            }
            sort(edge.begin(), edge.end(), [&](S a, S b) {
                return a.w < b.w;
            });
            for (int i = 0; i < edge.size(); i ++) {
                auto [u, v, w] = edge[i];
                int pu = find(u), pv = find(v);
                if (pu != pv) {
                    cnt ++;
                    sum += w;
                    merge(u, v);
                }
            }
            if (cnt < k - 1) cout << -1 << '\n';
            else cout << sum << '\n';
        } else {
            for (int i = 1; i <= m; i ++) {
                auto [u, v, w] = val[i];
                int pu = find(u), pv = find(v);
                if (pu != pv && query[u] && query[v]) {
                    cnt ++;
                    sum += w;
                    merge(u, v);
                }
            }
            if (cnt < k - 1) cout << -1 << '\n';
            else cout << sum << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}