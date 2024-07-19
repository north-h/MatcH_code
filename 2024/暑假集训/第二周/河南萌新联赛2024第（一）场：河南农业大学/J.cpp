// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

char a[5010][5010];
int s[5010][5010];
int n, m, dp[5010][5010];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            char op; cin >> op;
            s[n - i + 1][j] = (op - '0');
            a[n - i + 1][j] = op;
            // dp[i][j] = 1;
            if (op == '1') dp[n - i + 1][j] = 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    auto check = [&](int x, int y, int cnt, int op) -> bool {
        int i = x - cnt, j = y - cnt, sum = cnt * 3 + 1;
        if (a[i][y] != '1') return false;
        if (a[x][j] != '1') return false;
        if (a[x][y] != '1') return false;
        if (s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1] != sum) return false;
        return true;
    };
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int len = dp[i - 1][j - 1];
            if (check(i, j, len, 0)) dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (check(i, j, len - 1, 1)) dp[i][j] = dp[i - 1][j - 1];
            cout << dp[i][j] << ' ';
            ans = max(ans, dp[i][j]);
        }
        cout << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

