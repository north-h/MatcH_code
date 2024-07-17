// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], vis[N], d[N], son[N], vi[N];
vector<int> g[N];
int ans, n, idx, cnt;
map<int, vector<int>> mp;


void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (vis[son[t]]) continue;
        d[son[t]] --;
        if (d[son[t]] == 1) {
            q.push(son[t]);
            vis[son[t]] = 1;
        }
    }
}
void dfs(int u) {
    if (vi[u]) return ;
    vi[u] = 1;
    mp[idx].push_back(u);
    dfs(son[u]);
};

void dfs1(int u, int d) {
    if (!g[u].size()) {
        cnt = max(cnt, d);
    }
    for (auto v : g[u]) {
        if (vi[v]) continue;
        dfs1(v, d + 1);
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> son[i];
        g[son[i]].push_back(i);
        d[i] ++;
        d[son[i]] ++;
    }
    topsort();
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 2 && !vi[i]) dfs(i), idx ++;
    }
    for (auto [x, y] : mp) {
        int len = 0;
        for (auto j : y) {
            cnt = 0;
            dfs1(j, 0);
            len = max(len, cnt);
        }
        ans = max(ans, (int)y.size() + len);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}