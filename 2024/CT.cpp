// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII =  pair<int, int>;

void solve() {
    int n; cin >> n;
    if (n == 0) cout << '#' << '\n';
    if (n == 1) {
        cout << "###\n" << "#.#\n" << "###\n";
    } else {
        int m = pow(3, n);
        // debug1(m);
        vector<vector<char>> g(m + 1, vector<char> (m + 1, '#'));
        // for (int i = 1; i <= m; i ++) {
        //     for (int j = 1; j <= m; j ++) {
        //         cout << g[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        for (int i = 2; i <= m; i += 3) {
            for (int j = 2; j <= m; j += 3) {
                g[i][j] = '.';
            }
        }
        for (int i = 4; i <= m; i += 9) {
            for (int j = 4; j <= m; j += 9) {
                for (int x = i; x < i + 3; x ++) {
                    for (int y = j; y < j + 3; y ++) {
                        g[x][y] = '.';
                    }
                }
            }
        }

        if (n >= 4) {
            for (int i = 10; i <= m; i += 27) {
                for (int j = 10; j <= m; j += 27) {
                    // debug2(i, j);
                    // g[i][j] = '.';
                    for (int x = i; x < i + 9; x ++) {
                        for (int y = j; y < j + 9; y ++) {
                            g[x][y] = '.';
                            // debug2(x, y);
                        }
                    }
                }
            }
        }

        if (n >= 5) {
            for (int i = 28; i <= m; i += 81) {
                for (int j = 28; j <= m; j += 81) {
                    // debug2(i, j);
                    // g[i][j] = '.';
                    for (int x = i; x < i + 27; x ++) {
                        for (int y = j; y < j + 27; y ++) {
                            g[x][y] = '.';
                            // debug2(x, y);
                        }
                    }
                }
            }
        }

        if (n >= 6) {
            for (int i = 82; i <= m; i += 243) {
                for (int j = 82; j <= m; j += 243) {
                    // debug2(i, j);
                    // g[i][j] = '.';
                    for (int x = i; x < i + 81; x ++) {
                        for (int y = j; y < j + 81; y ++) {
                            g[x][y] = '.';
                            // debug2(x, y);
                        }
                    }
                }
            }
        }
        // for (int i = 4; i <= m; i += 6) {
        //     for (int j = 4; j <= m; j += 6) {
        //         for (int x = i; x <= i + 3; x ++) {
        //             for (int y = j; j <= i + 3; y ++) {
        //                 g[i][j] = '.';
        //             }
        //         }
        //     }
        // }
        int x = pow(3, n - 1);
        // debug2(x, m);
        for (int i = x + 1; i <= x + x; i ++) {
            for (int j = x + 1; j <= x + x; j ++) {
                g[i][j] = '.';
            }
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= m; j ++) {
                cout << g[i][j];
            }
            cout << '\n';
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
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
