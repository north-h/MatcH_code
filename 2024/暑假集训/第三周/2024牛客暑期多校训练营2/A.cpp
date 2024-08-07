// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int x, y; char t; cin >> x >> y >> t;
    vector g(n + 1, vector<char>(m + 1));
    if (t == 'A') {
        if ((x & 1) == (y & 1)) g[1][1] = 'A';
        else g[1][1] = 'B';
    } else {
        if ((x & 1) == (y & 1)) g[1][1] = 'B';
        else g[1][1] = 'A';
    }
    // debug1(g[1][1]);
    int smx = n + m, smn = n + m;
    if (m & 1) smx += (m / 2) * (n - 1);
    else {
        int c1, c2;
        if (g[1][1] == 'B') c2 = m / 2, c1 = c2 - 1;
        else c1 = m / 2, c2 = c1 - 1;
        // debug2(n, m);
        // debug2(c1, c2);
        if (n & 1) smx += (c1 + c2) * (n / 2);
        else smx += (c1 + c2) * (n / 2 - 1) + c1;
    }
    // debug2(smn, smx);
    cout << smn << ' ' << smx << '\n';
    // if (k < smn || k > smx) {
    //     cout << "No\n";
    //     return ;
    // }
    // for (int i = 2; i <= m; i ++) {
    //     if (g[1][i - 1] == 'A') g[1][i] = 'B';
    //     else g[1][i] = 'A';
    // }
    // for (int i = 2; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         if (g[i - 1][j] == 'A') g[i][j] = 'B';
    //         else g[i][j] = 'A';
    //     }
    // }
    // bool ok = false;
    // int cnt = smx - k;
    // for (int i = 2; i <= n; i ++) {
    //     for (int j = 1; j < m; j ++) {
    //         if (g[i][j] == 'B') {
    //             g[i][j] = 'A';
    //             cnt --;
    //             if (cnt == 0) {
    //                 ok = true;
    //                 break;
    //             }
    //         }
    //     }
    //     if (ok) break;
    // }
    // cout << "Yes\n";
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << g[i][j];
    //     }
    //     cout << '\n';
    // }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}