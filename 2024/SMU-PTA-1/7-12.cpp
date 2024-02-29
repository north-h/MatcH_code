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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    int ans1 = 0, ans2 = 0;
    auto bfs = [&](int x, int y) -> void {
        queue <PII> Q;
        Q.push({x, y});
        ans1 ++;
        int ok = 0;
        if(g[x][y] > '1') ok=1;
        g[x][y] = '0';

        while(!Q.empty())
        {
            auto t = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i ++)
            {
                int x = t.fi + dx[i],y = t.se + dy[i];
                if(x < 1 || x > n || y < 1 || y > m) continue;
                if(g[x][y] == '0') continue;
                if(g[x][y] > '1') ok=1;
                g[x][y] = '0';
                Q.push({x,y});
            }
        }
        ans2 += ok;
    };
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i][j] == '1') {
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    cout << ans1 <<' ' << ans2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}