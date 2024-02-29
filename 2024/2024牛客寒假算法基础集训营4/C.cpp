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

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    auto YDH = [&](int x) -> void {
        char op = g[x][m];
        for (int i = m; i >= 2; i --) {
            g[x][i] = g[x][i - 1];
        }
        g[x][1] = op;
    };
    auto YDL = [&](int x) -> void {
        char op = g[n][x];
        for (int i = n; i >= 2; i --) {
            g[i][x] = g[i - 1][x];
        }
        g[1][x] = op;
    };
    int p, q;
    cin >> p >> q;
    vector<PII> opz(q + 1);
    for (int i = 1; i <= q; i ++) {
        cin >> opz[i].fi >> opz[i].se;
    }
    while (p --) {
        for (int i = 1; i <= q; i ++) {
            if (opz[i].fi == 1) YDH(opz[i].se);
            else YDL(opz[i].se);
        }
    }
    cout << g[x][y] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}