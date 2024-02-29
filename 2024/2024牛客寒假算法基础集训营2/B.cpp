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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<PII> pos;
    vector<vector<int>> h(n + 2, vector<int>(m + 1));
    vector<vector<int>> l(n + 1, vector<int>(m + 2));
    for (int i = 1; i <= k; k ++) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }
    for (int i = 0; i < k; k ++) {
        int x = pos[i].fi, y = pos[i].se;
        h[x][y] ++;
        h[x + 1][y] ++;
        l[x][y] ++;
        l[x][y + 1] ++;
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i ++) {
        for (int j = 1; j <= m; j ++) {
            ans += (h[i][j] != 0);
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m + 1; j ++) {
            ans += (l[i][j] != 0);
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