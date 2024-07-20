// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {1, 0, -1, 0, 0};

void solve() {
    int n; cin >> n;
    vector<vector<char>> g(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            int ok = 0;
            for (int k = 0; k <= 4; k ++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > n) continue;
                if (g[x][y] == '#') continue;
                ok ++;
            }
            if (ok == 5) {
                // debug2(i, j);
                for (int k = 0; k <= 4; k ++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    g[x][y] = '#';
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (g[i][j] != '#') {
                cout << "NO" << '\n';
                return ;
            }
        }
    }
    cout << "YES" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}