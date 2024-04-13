// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

char g[1010][1010], ans[1010][1010];
int n, m;
int dx[8] = {1, 1, 0, 0, -1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 1, -1, 0, 0};


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            ans[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (ans[i][j] != '#') continue;
            if (g[i][j] == 'M') ans[i][j] = g[i][j];
            else if (g[i][j] == 'H') {
                for (int k = 0; k < 8; k ++) {
                    int x = dx[k] + j; int y = dy[k] + j;
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    ans[x][y] = 'G';
                }
            }
            else {
                int c = 0, v = 0;
                for (int k = 0; k < 8; k ++) {
                    int x = dx[k] + j; int y = dy[k] + j;
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    if (g[x][y] == 'L') c ++;
                    if (g[x][y] == 'H') v ++;
                    if (g[x][y] != 'H' && g[x][y] != 'M') ans[x][y] = 'N';
                }
                // debug2(i, j);
                // debug2(c, v);
                if (g[i][j] == 'L') {
                    if (c == 8) ans[i][j] = 'S';
                    else ans[i][j] = 'B';
                } else ans[i][j] = 'B';
            }
        }
    }
//     debug2(n, m);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
//    cin >> h_h;
    while (h_h--)solve();
    return 0;
}