// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<array<int, 3>>> g(n + 1);
    for (int i = 1; i <= m; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
    vector<int> dis(n + 1, 1e15);
    q.push({0, 1});
    dis[1] = 0;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        if (dis[t[1]] < t[0]) continue;
        for (auto [x, y, z] : g[t[1]]) {
            int T = t[0];
            if (t[0] <= round(sqrt(z)) - 1) {
                T = round(sqrt(z)) - 1;
            }
            T += y + z / (T + 1);
            if (dis[x] > T) {
                dis[x] = T;
                q.push({T, x});
            }

        }
    }
    if (dis[n] == 1e15) cout << -1 << '\n';
    else cout << dis[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}