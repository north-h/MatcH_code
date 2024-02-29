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
const int N = 65;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[N][N][N][N];
int x1 = 0, y1 = 0, x2, y2;
int ans = INF;
int n;

bool check(int x1, int y1, int x2, int y2) {
    if (x1 < 1 || x1 > n) return false;
    if (y1 < 1 || y1 > n) return false;
    if (x2 < 1 || x2 > n) return false;
    if (y2 < 1 || y2 > n) return false;
    return true;
}

void dfs(int x, int y, int xx, int yy) {
    if (x == x1 && y ==y1 && x2 == xx && y2 == yy) {
        ans = min(ans, vis[x][y][xx][yy]);
    }
    for (int i = 0; i < 4; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        int txx = xx + dx[i], tyy = yy + dy[i];
        if (!check(tx, ty, txx, tyy)) continue;
        if (vis[tx][ty][txx][tyy] || g[tx][ty] == '#' || g[]) continue;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 'P') {
                if (!x1 && !y1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    dfs(x1, y1, x2, y2);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}