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
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    auto b = a;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < m; j ++) {
            for (int k = 1; k <= 3; k ++) {
                if (a[i][j] == b[i][j]) break;
                a[i][j] = (a[i][j] - '0' + 1) % 3 + '0';
                a[i + 1][j + 1] = (a[i + 1][j + 1] - '0' + 1) % 3 + '0';
                a[i + 1][j] = (a[i + 1][j] - '0' + 2) % 3 + '0';
                a[i][j + 1] = (a[i][j + 1] - '0' + 2) % 3 + '0';
            }
        }
    }
    if (a != b) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}