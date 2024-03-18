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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    int sx, sy, ex, ey;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') sx = i, sy = j;
            if (g[i][j] == 'T') ex = i, ey = j;
        }
    }
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));    
    queue<array<int, 3>> q;
    d[sx][sy] = 0;
    // debug2(ex, ey);
    for (int i = 0; i < 4; i ++) {
        int x = sx + dx[i];
        int y = sy + dy[i];
        if (x < 1 || y < 1 || x > n || y > m) continue;
        if (g[x][y] == '#') continue;
        q.push({x, y, i});
        d[x][y] = d[sx][sy] + 1;
    }
    while (q.size()) {
        auto [x, y, z] = q.front();
        q.pop();
        if (g[x][y] == '*') {
            for (int i = 0; i < 4; i ++) {
                if (i == z) continue;
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
                if (g[tx][ty] == '#' || d[tx][ty] != INF) continue;
                q.push({tx, ty, i});
                d[tx][ty] = d[x][y] + 1;                
            }
        } else {
            int tx = x + dx[z];
            int ty = y + dy[z];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (g[x][y] == '#' || d[tx][ty] != INF) continue;
            q.push({tx, ty, z});
            d[tx][ty] = d[x][y] + 1;
        }
    }
    if (d[ex][ey] == INF) cout << -1 << endl;
    else cout << d[ex][ey] << endl;
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