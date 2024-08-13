// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1, '1'));
    for (int i = 2; i < n; i ++) {
        if (i % 2 == 0) {
            for (int j = 2; j < m; j += 2) g[i][j] = '*';
        } else {
            for (int j = 3; j < m; j += 2) g[i][j] = '*';
        }
    }
    for (int i = 3, j = 3; i < n && j < m; i += 2, j += 2) {
        if (g[i][j] == )
    }
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