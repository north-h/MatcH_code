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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = INF;
    if (k <= m) {
        for (int i = 1; i <= n; i++) {
            int d = 0, o = 0, x = 0;
            for (int j = 1; j <= k; j++) {
                if (g[i][j] == '.') d++;
                else if (g[i][j] == 'o') o++;
                else x++;
            }
            if (x == 0) {
                ans = min(ans, d);
            }
            for (int j = k + 1; j <= m; j++) {
                if (g[i][j] == '.') d++;
                else if (g[i][j] == 'o') o++;
                else x++;

                if (g[i][j - k] == '.') d--;
                else if (g[i][j - k] == 'o') o--;
                else x--;

                if (x == 0) {
                    ans =min(ans, d);
                }
            }
        }
    }
    if (k <= n) {
        for (int i = 1; i <= m; i++) {
            int d = 0, o = 0, x = 0;
            for (int j = 1; j <= k; j++) {
                if (g[j][i] == '.') d++;
                else if (g[j][i] == 'o') o++;
                else x++;
            }
            if (x == 0) {
                ans = min(ans, d);
            }
            for (int j = k + 1; j <= n; j++) {
                if (g[j][i] == '.') d++;
                else if (g[j][i] == 'o') o++;
                else x++;

                if (g[j - k][i] == '.') d--;
                else if (g[j - k][i] == 'o') o--;
                else x--;

                if (x == 0) {
                    ans =min(ans, d);
                }
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}