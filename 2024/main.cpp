// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

char g[110][110];
vector<array<int, 2>> a;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int x, int y) {
    vector<vector<int>> d(n + 10, vector<int>(m + 10, INF));
    queue<array<int, 2>> q;
    q.push({x, y});
    d[x][y] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (g[t[0]][t[1]] == 'T') return d[t[0]][t[1]];
        for (int i = 0; i < 4; i ++) {
            int tx = t[0] + dx[i];
            int ty = t[1] + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (d[tx][ty] != INF || g[tx][ty] == '#') continue;
            d[tx][ty] = d[t[0]][t[1]] + 1;
            q.push({tx, ty});
        }
    }
    return INF;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') a.push_back({i, j});
        }
    }
    int ans = 0;
    for (auto [x, y] : a) {
        ans += bfs(x, y);
    }
    cout << ans << '\n';
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