// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int x1 = 1, y1 = 1, x2 = 1, y2 = 2;
int x = 1, y = 0, n;
map<int, int> mp;
int g[110][110];

void solve() {
    y ++;
    if (y > n) x ++, y = 1;
    int a; cin >> a;
    if (a == 1) {
        if (x2 > n) {
            bool ok = false;
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    if (g[i][j] == 0) {
                        cout << 3 << ' ' << i << ' ' << j << endl;
                        g[i][j] = 3;
                        ok = true;
                        y1 += 2;
                        if (y1 > n) {
                            x1 ++;
                            if (x1 & 1) y1 = 1;
                            else y1 = 2;
                        }
                        break;
                    }
                }
                if (ok) break;
            }
        } else {
            cout << 2 << ' ' << x2 << ' ' << y2 << endl, g[x2][y2] = 2;
            y2 += 2;
            if (y2 > n) {
                x2 ++;
                if (x2 & 1) y2 = 2;
                else y2 = 1;
            }
        }
    } else if (a == 2) {
        if (x1 > n) {
            bool ok = false;
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    if (g[i][j] == 0) {
                        cout << 3 << ' ' << i << ' ' << j << endl;
                        g[i][j] = 3;
                        ok = true;
                        y2 += 2;
                        if (y2 > n) {
                            x2 ++;
                            if (x2 & 1) y2 = 2;
                            else y2 = 1;
                        }
                        break;
                    }
                }
                if (ok) break;
            }
        } else {
            cout << 1 << ' ' << x1 << ' ' << y1 << endl, g[x1][y1] = 1;
            y1 += 2;
            if (y1 > n) {
                x1 ++;
                if (x1 & 1) y1 = 1;
                else y1 = 2;
            }
        }
    } else {
        bool ok = false;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (g[i][j] == 0) {
                    if (i & 1) {
                        if (j & 1) {
                            cout << 1 << ' ' << i << ' ' << j << endl;
                            g[i][j] = 1;
                            y1 += 2;
                            if (y1 > n) {
                                x1 ++;
                                if (x1 & 1) y1 = 1;
                                else y1 = 2;
                            }
                        } else {
                            cout << 2 << ' ' << i << ' ' << j << endl;
                            g[i][j] = 2;
                            y2 += 2;
                            if (y2 > n) {
                                x2 ++;
                                if (x2 & 1) y2 = 2;
                                else y2 = 1;
                            }
                        }
                    } else {
                        if (j & 1) {
                            cout << 2 << ' ' << i << ' ' << j << endl;
                            g[i][j] = 2;
                            y2 += 2;
                            if (y2 > n) {
                                x2 ++;
                                if (x2 & 1) y2 = 2;
                                else y2 = 1;
                            }
                        } else {
                            cout << 1 << ' ' << i << ' ' << j << endl;
                            g[i][j] = 1;
                            y1 += 2;
                            if (y1 > n) {
                                x1 ++;
                                if (x1 & 1) y1 = 1;
                                else y1 = 2;
                            }
                        }
                    }
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> n;
    int T = n * n;
    while (T --)solve();
    return 0;
}