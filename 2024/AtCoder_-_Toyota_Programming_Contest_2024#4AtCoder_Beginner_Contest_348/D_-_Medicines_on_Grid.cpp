/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-06 20:36:31 ms
 *
 * Problem: D - Medicines on Grid
 * Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
 * URL:     https://atcoder.jp/contests/abc348/tasks/abc348_d
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 210;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[N][N];
int vis[N][N], e[N][N], d[N][N];
array<int, 2> S, E;
int n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool bfs(int x, int y) {
    queue<array<int, 3>> q;
    q.push({x, y, e[x][y]});
    vis[x][y] = 1;
    d[x][y] = e[x][y];
    while (q.size()) {
        auto t = q.front();
        q.pop();
        vis[t[0]][t[1]] = 0;
        if (t[0] == E[0] && t[1] == E[1] && t[2] >= 0) return true;
        if (t[2] <= 0 ) continue;
        for (int i = 0; i < 4; i ++) {
            int tx = t[0] + dx[i];
            int ty = t[1] + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (vis[tx][ty] || g[tx][ty] == '#') continue;
            if (e[tx][ty] > t[2]) q.push({tx, ty, e[tx][ty]}), d[tx][ty] = e[tx][ty];
            else q.push({tx, ty, t[2] - 1}), d[tx][ty] = t[2] - 1;;
            vis[tx][ty] = 1;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') S[0] = i, S[1] = j;
            if (g[i][j] == 'T') E[0] = i, E[1] = j;
        }
    }   
    cin >> k;
    for (int i = 1; i <= k; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x][y] = z;
    }
    auto t = bfs(S[0], S[1]);
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    if (t) cout << "Yes\n";
    else cout << "No\n";
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