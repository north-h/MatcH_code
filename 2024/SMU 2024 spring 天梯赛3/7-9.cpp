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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
int d[N], vis[N];
vector<PII> g[N];

void dijkstra(int u) {
    d[u] = 0;
    priority_queue<PII, vector<PII>, greater<PII>()> pq;
    pq.push({0, u});
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t.se])continue;
        vis[t.se] = 1;
        for (auto [x, y] : g[t.se]) {
            if (d[x] > d[t.se] + y) {
                d[x] = d[t.se] + y;
                pq.push({d[x], x});
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
    int id = -1, len = INF;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            vis[j] = 0;
            d[j] = INF;
        }
        dijkstra(i);
        int cnt = 0, mx = 0;
        for (int j = 1; j <= n; j ++) {
            mx = max(mx, d[j]);
            if (vis[j]) cnt ++;
        }
        if (len > mx && cnt == n) {
            len = mx;
            id = i;
        }
    }
    if (id == -1) cout << 0 << endl;
     else cout << id << ' ' << len << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}