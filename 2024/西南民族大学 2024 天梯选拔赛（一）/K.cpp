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
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[110][110];
int vis[110][110], d[110][110];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;
int sx, sy, ex, ey, ans = INF;

int bfs(int sx, int sy, int ex, int ey, int c) {
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m ; ++j) {
            d[i][j] = vis[i][j] = 0;
        }
    }
    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        // debug2(t.fi, t.se);
        vis[t.fi][t.se] = 1;
        for (int i = 0; i < 4 ; ++i) {
            int x = t.fi + dx[i];
            int y = t.se + dy[i];
            if(x >= 1 and x <= n and y >= 1 and y <= m and !vis[x][y]) {
                d[x][y] = d[t.fi][t.se] + c;
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
    }
    return d[ex][ey];
}

int bfs1(int sx, int sy, int ex, int ey, int c) {
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m ; ++j) {
            d[i][j] = vis[i][j] = 0;
        }
    }
    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        // debug2(t.fi, t.se);
        vis[t.fi][t.se] = 1;
        for (int i = 0; i < 4 ; ++i) {
            int x = t.fi + dx[i];
            int y = t.se + dy[i];
            if(x >= 1 and x <= n and y >= 1 and y <= m and !vis[x][y] and g[x][y] != '#') {
                d[x][y] = d[t.fi][t.se] + c;
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
    }
    return d[ex][ey];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    vector<PII> v(3);
    vector<int> vv(3), mp(3);
    for (int i = 0; i < 3; i ++) {
        cin >> v[i].fi >> v[i].se;
        vv[i] = i;
    }
    cin >> ex >> ey;
    for (int i = 0, x; i < 3; i ++) {
        cin >> x;
        mp[i] = x;
    }
    int ans = INF;
    do {
        // for (auto i : vv) cout << i << " \n"[i == vv.back()];
        // for (auto i : vv) {
        //     cout << v[i].fi << ' ' << v[i].se << '|' << mp[i] << endl;
        // }
        int res = 0, c = 0;
        c += 1;
        res += bfs(sx, sy, v[vv[0]].fi, v[vv[0]].se, c);
        // debug2(res, c);
        c += mp[vv[0]];
        res += bfs(v[vv[0]].fi, v[vv[0]].se, v[vv[1]].fi, v[vv[1]].se, c);
        // debug2(res, c);
        c += mp[vv[1]];
        res += bfs(v[vv[1]].fi, v[vv[1]].se, v[vv[2]].fi, v[vv[2]].se, c);
        // debug2(res, c);
        c += mp[vv[2]];
        res += bfs1(v[vv[2]].fi, v[vv[2]].se, ex, ey, c);
        // debug2(res, c);
        // res += bfs1(ex, ey, sx, sy);
        // debug1(res);
        ans = min(ans, res);
        // int i = vv[0], j = vv[1], k = vv[2];
        // bfs3(v[i].fi, v[i].se, v[j].fi, v[j].se, v[k].fi, v[k].se, i, j, k);
    } while (next_permutation(vv.begin(), vv.end()));
    cout << ans << endl;
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
