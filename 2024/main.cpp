// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

int get(int x) {
    int v = 0;
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= x; j ++) {
            int t = i * i + j * j;
            if (t >= x * x && t < (x + 1) * (x + 1)) {
                v ++;
                // cout << i << ' ' << j << '\n';
            }
        }
    }
    return v;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
    auto check = [&] (int x, int y) -> bool {
        int v = x * x + y * y;
        int c1 = n * n, c2 = (n + 1) * (n + 1);
        if (v >= c1 && v < c2) return true;
        return false;
    };
    ll ans = 0;
    for (int i = 1, j = n; i <= n && i < j; i ++) {
        if (check(i, j))  {
            if (!vis[i][j] && i != j) ans ++, vis[i][j] = 1;
            if (check(i, j - 1) && !vis[i][j - 1] && i != j - 1) {
                ans ++;
                vis[i][j - 1] = 1;
            }
        } else {
            j --;
            i --;
        }
    }
    ans *= 2;
    double t = floor((n + 1) * 1.0 / sqrt(2)) * sqrt(2);
    if (t >= n && t < n + 1) ans ++;
    cout << ans * 4 + 4 << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}