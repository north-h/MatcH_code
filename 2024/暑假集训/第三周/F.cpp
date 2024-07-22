// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define int long long
const int N = 200000;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
    int n; cin >> n;
    map<pair<int, int>, int> vis;
    map<pair<int, int>, pair<int, int>> ans;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
        vis[ {a[i].first, a[i].second}] = 1;
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 4; j ++) {
            int x = a[i].first + dx[j];
            int y = a[i].second + dy[j];
            if (!vis.count({x, y})) {
                q.push({a[i].first, a[i].second});
                ans[ {a[i].first, a[i].second}] = {x, y};
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int j = 0; j < 4; j ++) {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if (vis.count({tx, ty}) && !ans.count({tx, ty})) {
                ans[ {tx, ty}] = ans[ {x, y}];
                vis[ {tx, ty}] = 1;
                q.push({tx, ty});
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        auto [t1, t2] = ans[ {a[i].first, a[i].second}];
        cout << t1 << ' ' << t2 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}