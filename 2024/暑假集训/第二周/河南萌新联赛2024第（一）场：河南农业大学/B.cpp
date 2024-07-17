// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], vis[N], in[N], out[N];
vector<int> g[N];
int ans, n;


void topsort() {
    queue<int> q;
    vector<int> vi;
    for (int i = 1; i <= n; i ++) {
        if (!out[i]) q.push(i);
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (vis[i]) continue;
            in[i] --;
            out[t] --;
            if (!out[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

struct DSU {
    vector<int> fa, sz;
 
    DSU(int n) {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
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
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        g[a[i]].push_back(i);
        in[i] ++;
        out[a[i]] ++;
    }
    // vector<int> iin = in;
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (auto j : g[i]) cout << j << ' ';
        cout << '\n';
    }
    topsort();
    vector<int> ve(n + 1);
    set<int> st;
    int cnt = 0;
    map<int, vector<int>> mp;
    auto dfs = [&](auto &&dfs, int u) -> void {
        ve[u] = 1;
        st.insert(u);
        for (auto v : g[u]) {
            if (ve[v]) continue;
            dfs(dfs, v);
        }
    };
    int huan = 0;
    for (int i = 1; i <= n; i ++) {
        if (in[i] == 1 && !ve[i]) {
            cnt = 0;
            dfs(dfs, i);
            huan = max(huan, cnt);
        }
    }
    int lian = 0;
    auto dfs1 = [&](auto &&dfs, int u, int d) -> void {
        for (auto v : g[u]) {
            if (ve[u]) continue;
            ve[v] = 1;
            dfs(dfs, v, d + 1);
            ve[v] = 0;
        }
        lian = max(lian, d);
    };
    for (int i = 1; i <= n; i ++) {
        if (iin[i] == 1) {
            ve[i] = 1;
            dfs1(dfs1, i, 1);
            ve[i] = 1;
        }
    }
    debug2(huan, lian);
    cout << huan + lian << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}