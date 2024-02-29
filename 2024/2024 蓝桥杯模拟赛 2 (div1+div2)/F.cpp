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

vector<PII> g[N];
int n, m;

int dijkstra() {
    vector<int> dis(n + 1, INF), vis(n + 1);
    dis[1] = 0;
    priority_queue<PII, vector<PII >, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (vis[t.se])continue;
        vis[t.se] = true;
        for (auto [x, y] : g[t.se]) {
            if (dis[x] > dis[t.se] + y) {
                dis[x] = dis[t.se] + y;
                heap.push({dis[x], x});
            }
        }
    }
    return dis[n];
}


void solve() {
    cin >> n >> m;
    vector<int> gl(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> gl[i];
    }
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c + gl[a]});
        g[b].push_back({a, c + gl[b]});
    }
    cout << dijkstra() - gl[1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}