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
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;

char mp[N][N];
int d[N][N], vis[N][N];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;

int bfs() {
    memset(d, 0x3f, sizeof d);
    queue<PII> q;
    q.push({1, 1});
    vis[1][1] = 1;
    d[1][1] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m || vis[tx][ty] || mp[x][y] == mp[tx][ty]) continue;
            d[tx][ty] = min(d[tx][ty], d[x][y] + 1);
            q.push({tx, ty});
            vis[tx][ty] = 1;
        }
    }
    if (d[n][m] == INF) d[n][m] = -1;
    return d[n][m];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> mp[i][j];
        }
    }
    cout << bfs() << endl;
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