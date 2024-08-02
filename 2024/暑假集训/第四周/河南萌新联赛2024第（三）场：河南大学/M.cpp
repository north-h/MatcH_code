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
int vis[35][35][35][35];

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    map<array<int, 2>, int> mp;
    int m; cin >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        mp[ {x, y}] ++;
    }
    queue<array<int, 5>> q;
    q.push({x1, y1, x3, y3, 0});
    vis[x1][y1][x3][y3] = 1;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t[2] == x2 && t[3] == y2) {
            cout << t[4] << '\n';
            return ;
        }
        for (int i = 0; i < 4; i ++) {
            int x = t[0] + dx[i];
            int y = t[1] + dy[i];
            int xx = t[2], yy = t[3];
            if (x < 1 || y < 1 || x > 30 || y > 30 || mp[ {x, y}]) continue;
            if (x == xx && y == yy) {
                xx += dx[i];
                yy += dy[i];
            }
            if (xx >= 1 && yy >= 1 && xx <= 30 && yy <= 30 && !mp[ {xx, yy}] && !vis[x][y][xx][yy]) {
                q.push({x, y, xx, yy, t[4] + 1});
                vis[x][y][xx][yy] = 1;
            }
        }
    }
    cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}