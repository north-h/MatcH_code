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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][x] = 1;
    for (int i = 1; i <= m; i ++) {
        char op;
        int y;
        cin >> y >> op;
        for (int j = 1; j <= n; j ++) {
            int sy = (j + y) % n;
            int ny = (j - y + n) % n;
            if (sy == 0) sy = n;
            if (ny == 0) ny = n;
            if (op == '0') dp[i][sy] |= dp[i - 1][j];
            else if (op == '1') dp[i][ny] |= dp[i - 1][j];
            else {
                dp[i][sy] |= dp[i - 1][j];
                dp[i][ny] |= dp[i - 1][j];
            }
        }
    }
    set<int> ans;
    for (int i = 1; i <= n; i ++) {
        if (dp[m][i]) ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;
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