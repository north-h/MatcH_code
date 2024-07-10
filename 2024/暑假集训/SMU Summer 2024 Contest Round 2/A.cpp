// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII =  pair<int, int>;

void solve() {
    int n; cin >> n;
    int m = pow(3, n);
    vector<vector<char>> g(m + 1, vector<char> (m + 1, '#'));
    for (int i = 2; i <= m; i += 3) {
        for (int j = 2; j <= m; j += 3) {
            g[i][j] = '.';
        }
    }
    for (int k = 3; k <= n; k ++) {
        int x = pow(3, k - 2) + 1;
        for (int i = x; i <= m; i += pow(3, k - 1)) {
            for (int j = x; j <= m; j += pow(3, k - 1)) {
                for (int x = i; x < i + pow(3, k - 1) / 3; x ++) {
                    for (int y = j; y < j + pow(3, k - 1) / 3; y ++) {
                        g[x][y] = '.';
                    }
                }
            }
        }
    }
    int x = pow(3, n - 1);
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
