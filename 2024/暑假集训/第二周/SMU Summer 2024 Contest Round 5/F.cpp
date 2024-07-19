// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
char g[510][510];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, INF));
    deque<array<int, 2>> q;
    q.push_front({1, 1});
    dis[1][1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i ++) {
            int xx = t[0] + dx[i];
            int yy = t[1] + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if (g[xx][yy] == '#') continue;
            if (dis[xx][yy] <= dis[t[0]][t[1]]) continue;
            dis[xx][yy] = dis[t[0]][t[1]];
            q.push_front({xx, yy});
        }

        for (int i = t[0] - 2; i <= t[0] + 2; i ++) {
            for (int j = t[1] - 2; j <= t[1] + 2; j ++) {
                if (i == t[0] - 2 && j == t[1] + 2) continue;
                if (i == t[0] + 2 && j == t[1] + 2) continue;
                if (i == t[0] - 2 && j == t[1] - 2) continue;
                if (i == t[0] + 2 && j == t[1] - 2) continue;
                if (i < 1 || j < 1 || i > n || j > m) continue;
                if (dis[i][j] <= dis[t[0]][t[1]] + 1) continue;
                dis[i][j] = dis[t[0]][t[1]] + 1;
                q.push_back({i, j});
            }
        }
    }
    cout << dis[n][m] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}