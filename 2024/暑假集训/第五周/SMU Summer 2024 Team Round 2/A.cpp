// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int g[110][110];

void solve() {
    int n, m; cin >> n >> m;
    n ++; m ++;
    // debug2(n, m);
    g[1][1] = min(n, m) - 1;
    int zz = min(n, m);
        
    int x = (zz + 1) / 2, y = (zz + 1) / 2;
    debug2(x, y);
    if (m % 2 == 0) {
        int vv = (x - 1) * 2;
        for (int i = 2; i <= x; i ++) g[1][i] = g[1][i - 1] + vv, vv -= 2;
    } else {
        int vv = (x - 1) * 2 - 1;
        for (int i = 2; i <= x; i ++) g[1][i] = g[1][i - 1] + vv, vv -= 2;
    }
    int v;
    if (n % 2 == 0) {
        int vv = (y - 1) * 2;
        v = vv;
        for (int i = 2; i <= y; i ++) g[i][1] = g[i - 1][1] + vv, vv -= 2;
    } else {
        int vv = (y - 1) * 2 - 1;
        v = vv;
        for (int i = 2; i <= y; i ++) g[i][1] = g[i - 1][1] + vv, vv -= 2;
    }
    // debug1(v);
    for (int i = 2; i <= y; i ++) {
        for (int j = 2; j <= x; j ++) {
            g[i][j] = g[i - 1][j] + v;
        }
        v -= 2;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1, k = m; j <= k; j ++, k --) {
            g[i][k] = g[i][j];
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1, k = n; j <= k; j ++, k --) {
            g[k][i] = g[j][i];
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= (m + 1) / 2; j ++) {
    //         if (g[i][j] == 0)
    //             g[i][j] = g[i][j - 1];
    //     }
    //     for (int j = m - 1; j > (m + 1) / 2; j --) {
    //         if (g[i][j] == 0)
    //             g[i][j] = g[i][j + 1];
    //     }
    // }
    // for (int i = 1; i <= m; i ++) {
    //     for (int j = 1; j <= (n + 1) / 2; j ++) {
    //         if (g[j][i] == 0) {
    //             // debug2(j, i);
    //             g[j][i] = g[j - 1][i];
    //         }
    //     }
    //     for (int j = n - 1; j > (n + 1) / 2; j --) {
    //         if (g[j][i] == 0)
    //             g[j][i] = g[j + 1][i];
    //     }
    // }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}