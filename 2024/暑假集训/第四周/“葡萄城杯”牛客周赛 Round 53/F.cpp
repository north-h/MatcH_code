// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m, ans;
char g[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[N][N][5][2];

int bfs() {
    queue<array<int, 5>> q;
    q.push({1, 1, 2, 1, 0});
    q.push({1, 1, 3, 1, 0});
    q.push({1, 1, 4, 0, 0});
    vis[1][1][2][1] = 1;
    vis[1][1][3][1] = 1;
    vis[1][1][4][0] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            if (i == t[2]) continue;
            int tx = t[0] + dx[i];
            int ty = t[1] + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (vis[tx][ty][t[2]][t[3]]) continue;
            if (tx == n && ty == m) return t[4] + 1;
            if (g[tx][ty] == 'X') {
                if (t[3]) {
                    vis[tx][ty][t[2]][t[3]] = 1;
                    q.push({tx, ty, t[2], 0, t[4] + 1});
                }
            } else {
                vis[tx][ty][t[2]][t[3]] = 1;
                q.push({tx, ty, t[2], t[3], t[4] + 1});
            }
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << 0 << '\n';
        return ;
    }
    ans = bfs();
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
