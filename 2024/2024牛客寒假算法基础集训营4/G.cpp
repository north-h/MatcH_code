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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == '*') a[i][j] = 1;
        }
        for (int j = 1; j <= m; j ++) {
            a[i][j] += a[i][j - 1];
        }
    }
    auto check = [&](int x, int y) -> int {
        // debug2(x, y);
        int sum = 0;
        for (int i = x + 1, l = y - 1, r = y + 1; i <= n && l >= 1 && r <= m; i ++, l --, r ++) {
            // debug2(i, a[i][r] - a[i][l]);
            // debug2(l, r);
            if (a[i][r] - a[i][l - 1] == r - l + 1) sum ++;
            if (g[i][l] != '*' || g[i][r] != '*') break;
        }
        return sum;
    };
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i][j] == '*'){
                // debug2(i, j); 
                ans += check(i, j);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}