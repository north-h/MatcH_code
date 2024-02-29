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

int n;
int vis[1010][1010];
char g[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool bfs(int x, int y) {
    bool ok = true;
    queue<PII> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i ++) {
            int xx = t.fi + dx[i];
            int yy = t.se + dy[i];
            if (xx < 1 || yy < 1 || yy > n || xx > n) continue;
            if (g[xx][yy] == '.') continue;
            cnt ++;
            if (vis[xx][yy]) continue;
            debug2(xx, yy);
            q.push({xx, yy});
            vis[xx][yy] = 1;
        }
        if (cnt == 4) ok = false;
    }
    return ok;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!vis[i][j] && g[i][j] == '#') {
                // debug2(i, j);
                if (bfs(i, j)) ans ++; 
                // cout << endl;
            }
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= n; j ++) {
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}