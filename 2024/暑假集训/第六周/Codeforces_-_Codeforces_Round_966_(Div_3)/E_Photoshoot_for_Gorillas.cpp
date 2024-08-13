/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-13 22:41:26
 *
 * Problem: E. Photoshoot for Gorillas
 * Contest: Codeforces - Codeforces Round 966 (Div. 3)
 * URL:     https://codeforces.com/contest/2000/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int x, y, s;
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int w; cin >> w;
    vector<int> dxx(w);
    for (int i = 0; i < w; i ++) cin >> dxx[i];
    vector g(n + 2, vector<int>(m + 2));
    auto insert = [&](int x1, int y1, int x2, int y2, int c) -> void {
        g[x1][y1] += c;
        g[x2 + 1][y1] -= c;
        g[x1][y2 + 1] -= c;
        g[x2 + 1][y2 + 1] += c;
    };
    for (int i = k; i <= n; i ++) {
        for (int j = k; j <= m; j ++) {
            int x1 = i - k + 1, y1 = j - k + 1;
            int x2 = i, y2 = j;
            insert(x1, y1, x2, y2, 1);
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    vector<S> zb;
    vector cx(n + 1, vector <array<int, 2>>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            zb.push_back({i, j, g[i][j]});
        }
    }
    sort(zb.begin(), zb.end(), [&](S x, S y) {
        return x.s > y.s;
    });
    sort(dxx.rbegin(), dxx.rend());
    for (int i = 0; i < w; i ++) {
        auto [x, y, s] = zb[i];
        cx[x][y][0] = s;
        cx[x][y][1] = dxx[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ans += cx[i][j][0] * cx[i][j][1];
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}