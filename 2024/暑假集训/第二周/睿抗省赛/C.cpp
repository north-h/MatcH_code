#include<bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << '\n'
#define debug2(a, b) cout << #a << '=' << a << #b << '=' << b << '\n'
#define int long long

using namespace std;

char g[1010][1010];
int n, m;
int dx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int dy[] = {1, -1, 1, -1, 1, -1, 0, 0};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    vector<array<int, 2>> ans;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (g[i][j] != 'w') continue;
            vector<array<int, 2>> ve;
            bool ok = false;
            // debug2(i, j);
            for (int k = 0; k < 8; k ++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > m) continue;
                if (g[x][y] == '.') ve.push_back({x, y});
                else if (g[x][y] == 'm') ok = true;
            }
            if (!ok) {
                for (auto [x, y] : ve) {
                    // cout << x << ' ' << y << '\n';
                    bool f = true;
                    for (int l = 0; l < 8; l ++) {
                        int tx = x + dx[l];
                        int ty = y + dy[l];
                        if (tx < 1 || ty < 1|| tx > n || ty > m) continue;
                        if (g[tx][ty] == 'c') f = false;
                    }
                    if (f) ans.push_back({x, y});
                }
                // cout << "--------------" << '\n';
            } 
        }
    }
    sort(ans.begin(), ans.end());
    if (!ans.size()) cout << "Too cold!" << '\n';
    else {
        for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}

