/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-08 01:32:21
 *
 * Problem: Crazy 小飞象！
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/71508/I
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    vector<vector<int>> g(n + 1, vector<int> (m + 1));
    vector<vector<int>> ans(n + 1, vector<int> (m + 1, -1));
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cin >> g[i][j];
    //     }
    // }
    auto bfs = [&](int sx, int sy)->void{
        queue<PII> q;
        ans[sx][sy] = 0;
        q.push({sx, sy});
        int dx[4] = {2, 2, -2, -2};
        int dy[4] = {2, -2, 2, -2};
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = t.fi + dx[i];
                int y = t.se + dy[i];
                if(x < 1 || y < 1 || x > n || y > m)continue;
                if(ans[x][y] != -1)continue;
                ans[x][y] = ans[t.fi][t.se] + 1;
                q.push({x, y});
            }
        }
    };
    bfs(sx, sy);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}