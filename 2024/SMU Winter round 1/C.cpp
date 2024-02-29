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

struct edge {
    int x, y, id;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    int m;
    cin >> m;
    vector <int> n(m * m + 1), s(m * m + 1), w(m * m + 1), e( m * m + 1);
    vector<vector<int>> g(m + 1, vector<int>(m + 1, -1));
    queue <edge> q;
    for (int i = 1; i <= m * m; i++) {
        cin >> n[i] >> s[i] >> w[i] >> e[i];
        if (n[i] == -1 && w[i] == -1) {
            g[1][1] = i;
            q.push({1, 1, i});
        }
    }
    // for (int i = 2; i <= m; i++) g[i][1] = s[g[i - 1][1]];
    // for (int j = 2; j <= m; j++) {
    //     for (int i = 1; i <= m; i ++) {
    //         g[i][j] = e[g[i][j - 1]];
    //     }
    // }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            if (x < 1 || y < 1 || x >  m || y > m) continue;
            if (g[x][y] != -1) continue; 
            int idd;
            if (i == 0) g[x][y] = n[t.id], idd = n[t.id];
            else if (i == 1) g[x][y] = s[t.id], idd = s[t.id];
            else if (i == 2) g[x][y] = w[t.id], idd = w[t.id];
            else g[x][y] = e[t.id], idd = e[t.id];
            if (idd == -1) continue;
            q.push({x, y, idd});      
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << g[i][1];
        for (int j = 2; j <= m; j ++) {
            cout << ' ' << g[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}