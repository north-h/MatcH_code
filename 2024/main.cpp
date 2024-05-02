#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;

    using pii = pair<int, int> ;
    map<pii, int> mp;
    int cnt = 1;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    queue<pii> Q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (s[i][j] == 'S')
                mp[ {i, j}] = cnt ++;
            if (s[i][j] == 'T') {
                dis[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    vector<vector<int>> d(cnt, vector<int>(cnt, INT_MAX));
    const int u[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
    while (Q.size()) {
        auto [x, y] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i ++) {
            int dx = x + u[i];
            int dy = y + v[i];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && dis[dx][dy] == -1 && s[dx][dy] != '#') {
                dis[dx][dy] = dis[x][y] + 1;
                Q.push({dx, dy});
                if (s[dx][dy] == 'S') {
                    int to = mp[ {dx, dy}];
                    d[0][to] = d[to][0] = dis[dx][dy];
                }
            }
        }
    }

    auto bfs = [&](int a, int b) {
        queue<pair<pii, int>> q;
        q.push({{a, b}, 0});
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[a][b] = 1;
        int now = mp[ {a, b}];
        while (q.size()) {
            auto [xy, step] = q.front();
            q.pop();
            auto [x, y] = xy;
            for (int i = 0; i < 4; i ++) {
                int dx = x + u[i];
                int dy = y + v[i];
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] && s[dx][dy] != '#') {
                    vis[dx][dy] = 1;
                    if (s[dx][dy] == 'S') {
                        int to = mp[ {dx, dy}];
                        d[now][to] = d[to][now] = step + 1;
                    }
                    q.push({{dx, dy}, step + 1});
                }
            }
        }
    };

    for (auto [xy, cnt] : mp) {
        auto [x, y] = xy;
        bfs(x, y);
    }

    // for (int k = 0; k < cnt; k ++)
    //  for (int i = 0; i < cnt; i ++)
    //      for (int j = 0; j < cnt; j ++)
    //          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    // for (int i = 0; i < cnt; i ++)
    //  for (int j = 0; j < cnt; j ++)
    //      cout << d[i][j] << " \n"[j == cnt - 1];

    vector<vector<i64>> dp(cnt, vector<i64>(1 << cnt, INT_MAX));
    // for (int i = 0; i < cnt; i ++)
    //  dp[i][(1 << i)] = d[0][i];
    dp[0][1] = 0;

    for (int i = 1; i < (1 << cnt); i += 2) {
        for (int j = 0; j < cnt; j ++) {
            if (dp[j][i] == INT_MAX) continue;
            if ((i >> j) & 1) {
                for (int k = 0; k < cnt; k ++) {
                    if (!((i >> k) & 1)) {
                        // cout << "j:" << j << " k:" << k << '\n';
                        // cout << "i:";
                        // cout << bitset<8>(i) << '\n';
                        // cout << "->";
                        // cout << bitset<8>(i | (1 << k)) << '\n';
                        int to = i | (1 << k);
                        dp[k][to] = min(dp[k][to], dp[j][i] + min(d[j][k], d[0][k]));
                        // cout << "dp->:" << dp[k][i | (1 << k)] << '\n';
                    }
                }
            }
        }
    }

    i64 ans = INT_MAX;
    for (int i = 0; i < cnt; i++)
        ans = min(ans, dp[i][(1 << cnt) - 1]);
    cout << ans << '\n';

    return 0;
}
