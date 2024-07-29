#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define ft first
#define sd second
#define P pair<int, int>
#define Ios ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int N = 1e6 + 5;
int mp[1005][1005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};
int dp[N][3][2], d[N];
struct ty {
    int dis, dir, use, id;
    bool operator>(const ty &b) const {
//         if (dis == b.dis)
//             return use > b.use;
        return dis > b.dis;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            mp[i][j] = ch == 'X';
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = 0;
    priority_queue<ty, vector<ty>, greater<ty>> q;
    q.push({0, 0, 0, 0});
    q.push({0, 1, 0, 0});
    q.push({0, 2, 0, 0});
    while (!q.empty()) {
        ty now = q.top();
        q.pop();
        int id = now.id, dis = now.dis, use = now.use, dir = now.dir;
        int x = id / m, y = id % m;
        for (int i = 0; i < 4; i++) {
            if (dir != 2 && dir == i)
                continue;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int nxt = nx * m + ny;

            if (mp[nx][ny]) {
                if (dir < 2 && use == 0 && dp[nxt][dir][1] > dp[id][dir][0] + 1) {
                    dp[nxt][dir][1] = dp[id][dir][0] + 1;
                    q.push({dp[nxt][dir][1], dir, 1, nxt});
                }
            } else {
                if (dp[nxt][dir][use] > dp[id][dir][use] + 1) {
                    dp[nxt][dir][use] = dp[id][dir][use] + 1;
                    q.push({dp[nxt][dir][use], dir, use, nxt});
                }
            }
        }
    }
    int g = n * m - 1;
    int dis = min({dp[g][0][1], dp[g][1][1], dp[g][2][0]});
    cout << (dis >= n * m ? -1 : dis) << "\n";
}
signed main() {
    Ios;
    solve();
    return 0;
}