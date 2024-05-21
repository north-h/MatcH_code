#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool vis[100][100][10];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s) cin >> i;

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            char c = s[i][j];
            if (c == 'u' || c == 'o' || c == 'l' || c == 'r') {
                if (sx == -1) {
                    sx = i, sy = j;
                } else {
                    ex = i, ey = j;
                }
            }
        }
    }

    auto ans = s;
    auto debug = [&]()->void{
        for (auto i : ans)
            cout << i << '\n';
    };
    auto dfs = [&](auto self, int x, int y, int fx)->void{
        // cout << ans[x][y] << ' ' << fx << '\n' ;
        // debug();
        if (x == ex && y == ey) {
            char c = s[x][y];
            if (fx == 1 && c != 'o') return;
            if (fx == 2 && c != 'u') return;
            if (fx == 3 && c != 'l') return;
            if (fx == 4 && c != 'r') return;
            for (auto i : ans)
                cout << i << '\n';
            exit(0);
        }

        if (fx == 1) {
            if (x - 1 < 0) return ;
            char to = s[x - 1][y];
            if (to == 'i') {
                if (vis[x - 1][y][1] && vis[x - 1][y][2]) return;
                vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 1;
                self(self, x - 1, y, 1);
                vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 0;
            } else if (to == '+') {
                if (!vis[x - 1][y][1] && !vis[x - 1][y][2]) {
                    vis[x - 1][y][1] = vis[x - 1][y][2] = 1;
                    self(self, x - 1, y, 1);
                    vis[x - 1][y][1] = vis[x - 1][y][2] = 0;
                }
            } else if (to == 'p') {

                if (!vis[x - 1][y][2] && !vis[x - 1][y][3]) {
                    vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 1;
                    self(self, x - 1, y, 3);
                    vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 0;
                }

                if (!vis[x - 1][y][2] && !vis[x - 1][y][4]) {

                    vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 1;
                    ans[x - 1][y] = 'q';
                    self(self, x - 1, y, 4);
                    vis[x - 1][y][1] = vis[x - 1][y][2] = vis[x - 1][y][3] = vis[x - 1][y][4] = 0;
                    ans[x - 1][y] = 'p';
                }

            } else if (to == 'x') {
                if (!vis[x - 1][y][2] && !vis[x - 1][y][3]) {
                    vis[x - 1][y][2] = vis[x - 1][y][3] = 1;
                    self(self, x - 1, y, 3);
                    vis[x - 1][y][2] = vis[x - 1][y][3] = 0;
                }
                if (!vis[x - 1][y][2] && !vis[x - 1][y][4]) {
                    vis[x - 1][y][2] = vis[x - 1][y][4] = 1;
                    char t = ans[x - 1][y];
                    ans[x - 1][y] ^= 'x' ^ 'y' ;
                    self(self, x - 1, y, 4);
                    vis[x - 1][y][2] = vis[x - 1][y][4] = 0;
                    ans[x - 1][y] ^= 'x' ^ 'y' ;
                }
            } else {
                if (vis[x - 1][y][fx]) return;
                self(self, x - 1, y, fx);
            }
        } else if (fx == 2) {
            if (x + 1 >= n) return;
            char to = s[x + 1][y];
            if (to == 'i') {
                if (vis[x + 1][y][1] && vis[x + 1][y][2]) return;
                vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 1;
                self(self, x + 1, y, 2);
                vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 0;
            } else if (to == '+') {
                if (vis[x + 1][y][1] && vis[x + 1][y][2]) return;
                vis[x + 1][y][1] = vis[x + 1][y][2] = 1;
                self(self, x + 1, y, 2);
                vis[x + 1][y][1] = vis[x + 1][y][2] = 0;
            } else if (to == 'p') {
                if (!vis[x + 1][y][1] && !vis[x + 1][y][3]) {
                    ans[x + 1][y] = 'b';
                    vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 1;
                    self(self, x + 1, y, 3);
                    vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 0;
                }
                if (!vis[x + 1][y][1] && !vis[x + 1][y][4]) {
                    vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 1;
                    ans[x + 1][y] = 'd';
                    self(self, x + 1, y, 4);
                    vis[x + 1][y][1] = vis[x + 1][y][2] = vis[x + 1][y][3] = vis[x + 1][y][4] = 0;
                    ans[x + 1][y] = 'p';
                }
            } else if (to == 'x') {
                if (!vis[x + 1][y][1] && !vis[x + 1][y][4]) {
                    vis[x + 1][y][1] = vis[x + 1][y][4] = 1;
                    self(self, x + 1, y, 4);
                    vis[x + 1][y][1] = vis[x + 1][y][4] = 0;
                }
                if (!vis[x + 1][y][1] && !vis[x + 1][y][3]) {
                    vis[x + 1][y][1] = vis[x + 1][y][3] = 1;
                    ans[x + 1][y] ^= 'x' ^ 'y';
                    self(self, x + 1, y, 3);
                    vis[x + 1][y][1] = vis[x + 1][y][3] = 0;
                    ans[x + 1][y] ^= 'x' ^ 'y';
                }
            } else {
                if (vis[x + 1][y][fx]) return;
                self(self, x + 1, y, fx);
            }
        } else if (fx == 3) {
            if (y + 1 >= m) return ;
            char to = s[x][y + 1];
            if (to == 'i') {
                if (vis[x][y + 1][3] && vis[x][y + 1][4]) return;
                vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 1;
                ans[x][y + 1] = '-';
                self(self, x, y + 1, 3);
                vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 0;
                ans[x][y + 1] = 'i';
            } else if (to == '+') {
                if (vis[x][y + 1][3] && vis[x][y + 1][4]) return;
                vis[x][y + 1][3] = vis[x][y + 1][4] = 1;
                self(self, x, y + 1, 3);
                vis[x][y + 1][3] = vis[x][y + 1][4] = 0;
            } else if (to == 'p') {
                if (!vis[x][y + 1][1] && !vis[x][y + 1][4]) {
                    vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 1;
                    ans[x][y + 1] = 'd';
                    self(self, x, y + 1, 1);
                    vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 0;
                }
                if (!vis[x][y + 1][2] && !vis[x][y + 1][4]) {
                    vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 1;
                    ans[x][y + 1] = 'q';
                    self(self, x, y + 1, 2);
                    vis[x][y + 1][1] = vis[x][y + 1][2] = vis[x][y + 1][3] = vis[x][y + 1][4] = 0;
                    ans[x][y + 1] = 'p';
                }
            } else if (to == 'x') {
                if (!vis[x][y + 1][1] && !vis[x][y + 1][4]) {
                    vis[x][y + 1][1] = vis[x][y + 1][4] = 1;
                    self(self, x, y + 1, 1);
                    vis[x][y + 1][1] = vis[x][y + 1][4] = 0;
                }
                if (!vis[x][y + 1][2] && !vis[x][y + 1][4]) {
                    vis[x][y + 1][2] = vis[x][y + 1][4] = 1;
                    ans[x][y + 1] ^= 'x' ^ 'y';
                    self(self, x, y + 1, 2);
                    vis[x][y + 1][2] = vis[x][y + 1][4] = 0;
                    ans[x][y + 1] ^= 'x' ^ 'y';
                }
            } else {
                if (vis[x][y + 1][fx]) return;
                self(self, x, y + 1, fx);
            }
        } else if (fx == 4) {
            if (y - 1 < 0) return;
            char to = s[x][y - 1];
            if (to == 'i') {
                if (vis[x][y - 1][ 3] && vis[x][y - 1][4]) return;
                vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 1;
                ans[x][y - 1] = '-';
                self(self, x, y - 1, 4);
                vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 0;
                ans[x][y - 1] = 'i';
            } else if (to == '+') {
                if (vis[x][y - 1][3] && vis[x][y - 1][4]) return;
                vis[x][y - 1][3] = vis[x][y - 1][4] = 1;
                self(self, x, y - 1, 4);
                vis[x][y - 1][3] = vis[x][y - 1][4] = 0;
            } else if (to == 'p') {
                if (!vis[x][y - 1][2] && !vis[x][y - 1][3]) {
                    vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 1;
                    self(self, x, y - 1, 2);
                    vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 0;
                }
                if (!vis[x][y - 1][1] && !vis[x][y - 1][3]) {
                    vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 1;
                    ans[x][y - 1] = 'b';
                    self(self, x, y - 1, 1);
                    vis[x][y - 1][1] = vis[x][y - 1][2] = vis[x][y - 1][3] = vis[x][y - 1][4] = 0;
                    ans[x][y - 1] = 'p';
                }
            } else if (to == 'x') {
                if (!vis[x][y - 1][2] && !vis[x][y - 1][3]) {
                    vis[x][y - 1][2] = vis[x][y - 1][3] = 1;
                    self(self, x, y - 1, 2);
                    vis[x][y - 1][2] = vis[x][y - 1][3] = 0;
                }
                if (!vis[x][y - 1][1] && !vis[x][y - 1][3]) {
                    vis[x][y - 1][1] = vis[x][y - 1][3] = 1;
                    ans[x][y - 1] ^= 'x' ^ 'y';
                    self(self, x, y - 1, 1);
                    vis[x][y - 1][1] = vis[x][y - 1][3] = 0;
                    ans[x][y - 1] ^= 'x' ^ 'y';
                }
            } else {
                if (vis[x][y - 1][fx]) return;
                self(self, x, y - 1, fx);
            }
        }
    };

    int f = 0;
    char c = s[sx][sy];
    if (c == 'u') f = 1;
    else if (c == 'o') f = 2;
    else if (c == 'l') f = 4;
    else f = 3;

    for (int i = 1; i <= 4; i ++)
        vis[sx][sy][i] = 1;
    dfs(dfs, sx, sy, f);

    return 0;
}
