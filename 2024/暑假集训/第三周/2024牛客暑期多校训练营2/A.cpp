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
    for (int i = 2; i <= m; i ++) {
        if (g[1][i - 1] == 'A') g[1][i] = 'B';
        else g[1][i] = 'A';
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i - 1][j] == 'A') g[i][j] = 'B';
            else g[i][j] = 'A';
        }
    }
    int smx = n + m, smn = n + m;
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j < m; j ++) {
            if (g[i][j] == 'B') {
                smx ++;
            }
        }
    }
    if (k < smn || k > smx) {
        cout << "No\n";
        return ;
    }
    int cnt = smx - k;
    if (t == 'A') {
        for (int i = 2; i <= n && cnt > 0; i ++) {
            for (int j = 1; j < m && cnt > 0; j ++) {
                if (g[i][j] == 'B') {
                    g[i][j] = 'A';
                    cnt --;
                }
            }
        }
    } else {
        for (int i = 2; i <= n && cnt > 0; i ++) {
            for (int j = 2; j <= m && cnt > 0; j ++) {
                if (g[i][j] == 'A') {
                    g[i][j] = 'B';
                    cnt --;
                }
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << g[i][j];
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