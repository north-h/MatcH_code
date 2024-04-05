/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:22 ms
 *
 * Problem: P8662 [蓝桥杯 2018 省 AB] 全球变暖
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8662?contestId=165868
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

char g[N][N];
int vis[N][N];
int n;
int nw, af;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    vis[x][y] = 1;
    if (g[x][y] == '#') nw ++;
    bool ok = false;
    for (int i = 0; i < 4; i ++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 1 || ty < 1 || tx > n || ty > n || vis[tx][ty]) continue;
        if (g[tx][ty] == '.' && !ok) af ++, ok = true;
        if (g[tx][ty] == '#') dfs(tx, ty);
    }
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
            if (vis[i][j] || g[i][j] == '.') continue;
            nw = 0, af = 0;
            dfs(i, j);
            if (nw == af) ans ++;
        }
    }
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