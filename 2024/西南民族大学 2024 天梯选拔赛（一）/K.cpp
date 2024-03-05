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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

int g[110][110], vis[110][110], d[110][110];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;

int bfs(int x1, int y1, int x2, int y2) {
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    queue<PII> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;
    d[x1][y1] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (vis[tx][ty]) continue;
            d[tx][ty] = d[x][y] + 1;
            q.push({tx, ty});
            vis[tx][ty] = 1;
        }
    }
    return d[x2][y2];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
        }
    }
    int sx, sy, x1, y1, x2, y2, x3, y3, ex, ey;
    cin >> sx >> sy >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> ex >> ey ;
    int t1, t2, t3;
    vector<PII> v(3);
    cin >> v[0].fi >> v[1].fi >> v[2].fi;
    v[0].se = 1;
    v[0].se = 2;
    v[0].se = 3;
    int ans = INF;
    do {
        int res = 0;
        
        for (int i = 0; i < 3; i ++) {

        }
    } while (next_permutation(v.begin(), v.end()));
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}