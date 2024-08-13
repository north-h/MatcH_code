// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
    int n; cin >> n;
    vector vis(110, vector<int>(110, 0));
    double ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        if (vis[x][y]) continue;
        for (int j = 0; j < 4; j ++) {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if (tx < 0 || ty < 0 || tx > 100 || ty > 100) continue;
            if (vis[tx][ty]) continue;
            ans += 0.5;
        }
        // cout << ans << '\n';
        vis[x][y] = 1;
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