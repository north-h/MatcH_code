// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 30;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
int a[N][N], b[N][N];

int calc(int x, int y) {
    int res = 0;
    for (int i = 1, l = x; i <= n; i ++, l ++) {
        for (int j = 1, k = y; j <= n; j ++, k ++) {
            res += a[i][j] * b[l][k];
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i  = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i  = 1; i <= m; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i + n - 1 <= m; i ++) {
        for (int j = 1; j + n - 1 <= m; j ++) {
            cout << calc(i, j) << ' ';
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