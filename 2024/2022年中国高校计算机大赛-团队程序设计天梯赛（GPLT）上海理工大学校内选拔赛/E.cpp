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

int dx[8] = {1, -1, 1, -1, -2, -2, 2, 2};
int dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int n, m, k, a, b, c, d;
int g[310][310];

int bfs(int op) {
    vector<vector<int>> vis(310, vector<int>(310)), dis(310, vector<int>(310, INF));
    queue<PII> q;
    q.push({a,b});
    vis[a][b] = 1;
    dis[a][b] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t.fi == c && t.se == d) return dis[c][d];
        for (int i = 0; i < 8; i ++) {
            int x = t.fi + dx[i];
            int y = t.se + dy[i];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (vis[x][y] || g[x][y]) continue;
            if (op){
                if (dy[i] == 2) {
                    if (g[t.fi][t.se + 1]) continue;
                }else if (dy[i] == -2) {
                    if (g[t.fi][t.se - 1]) continue;
                } else if (dx[i] == -2) {
                    if (g[t.fi - 1][t.se]) continue;
                } else {
                    if (g[t.fi + 1][t.se]) continue;
                }
            }
            q.push({x, y});
            vis[x][y] = 1;
            dis[x][y] = dis[t.fi][t.se] + 1;
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m >> k >> a >> b >> c >> d;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            g[i][j] = 0;
        }
    }
    for (int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    cout << bfs(0) << ' ' << bfs(1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}