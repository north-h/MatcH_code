// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
vector<PII> g[N];
int dis[N];

void dijsktra() {
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i ++) dis[i] = 1e18;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t.se]) continue;
        vis[t.se] = 1;
        for (auto [x, y] : g[t.se]) {
            if (dis[x] > dis[t.se] + y) {
                dis[x] = dis[t.se] + y;
                pq.push({dis[x], x});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dijsktra();
    int T;
    cin >> T;
    while (T --) {
        int x, y;
        cin >> x >> y;
        cout << dis[x] + dis[y] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}