// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 2000;
const int INF = 0x3f3f3f3f;

using namespace std;

int f[2010][1010][2], a[2010];
int n, k;

void solve() {
    while (cin >> n >> k) {
        // cin >> n >> k;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= k; j ++) {
                f[i][j][0] = f[i][j][1] = INF;
            }
        }
        for (int i = 0; i <= n; i ++) f[i][0][0] = f[i][0][1] = 0;
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= k && j * 2 <= i; j ++) {
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1 ][j][1]);
                f[i][j][1] = f[i - 1][j - 1][0] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
            }
        }
        cout << min(f[n][k][0], f[n][k][1]) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}