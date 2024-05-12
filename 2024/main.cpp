// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 110;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;
using ll = long long;

ll dp[N * 2][N * 2][N];

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    int px = 100 - x, py = 100 - y;
    x = 100, y = 100;
    string s; cin >> s; s = " " + s;
    vector<int> a(n + 1);
    set<array<int, 2>> st;
    for (int i = 1; i <= m; i ++) {
        int xx, yy; cin >> xx >> yy;
        st.insert({xx + px, yy + py});
        // debug2(xx + px, yy + py);
    }
    dp[100][100][0] = 1;
    // debug2(x, y);
    for (int k = 1; k <= n; k ++) {
        for (int i = 0; i <= 200; i ++) {
            for (int j = 0; j <= 200; j ++) {
                dp[i][j][k] = dp[i][j][k - 1];
            }
        }
        // debug1(dp[100][100][k]);
        for (int i = 0; i <= 200; i ++) {
            for (int j = 0; j <= 200; j ++) {
                int tx = i, ty = j;
                if (s[k] == 'L') tx --;
                if (s[k] == 'R') tx ++;
                if (s[k] == 'U') ty ++;
                if (s[k] == 'D') ty --;
                if (tx < 0 || ty < 0 || tx > 200 || ty > 200) continue;
                if (st.count({tx, ty})) dp[i][j][k] = (dp[i][j][k] + dp[i][j][k - 1]) % mod;
                else dp[tx][ty][k] = (dp[i][j][k - 1] + dp[tx][ty][k]) % mod;
            }
        }
    }
    // cout << dp[100][100][1] << '\n';
    // cout << dp[100][100][2] << '\n';
    cout << dp[100][100][n] << '\n';
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