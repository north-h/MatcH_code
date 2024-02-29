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
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<PII> g[N * 2];
int n, m, k, ds;
map<int, string> mp;

int get(string s) {
    int id = 0;
    if (s[0] != 'G') {
        for (auto i : s) id = id * 10 + (i - '0');
        return id;
    } else {
        id = n;
        int x = 0;
        for (int i = 1; i < (int)s.size(); i ++) {
            x = x * 10 + (s[i] - '0');
        }
        return id + x;
    }
}

pair<double, double> dijkstra(int x) {
    vector<int> dis(n + m + 1, INF);
    dis[x] = 0;
    priority_queue<PII, vector<PII >, greater<PII>> heap;
    vector<int> vis (n + m + 1);
    heap.push({0, x});
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
    int ans = INF, res = 0;
    for (int i = 1; i <= n; i ++) {
        ans = min(ans, dis[i]);
        res += dis[i];
        if (dis[i] > ds) {
            return {-1.0, -1.0};
        }
    }
    return {ans * 1.0, res * 1.0 / n};
}

struct edge {
    double a;
    double b;
    int id;
};

void solve() {
    cin >> n >> m >> k >> ds;
    for (int i = 1; i <= k; i ++) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        // debug2(get(a), get(b));
        mp[get(a)] = a;
        mp[get(b)] = b;
        g[get(a)].push_back({get(b), c});
        g[get(b)].push_back({get(a), c});
    }
    vector<edge> ans;
    for (int i = n + 1; i <= n + m; i ++) {
        auto t = dijkstra(i);
        if (t.fi == -1.0 && t.se == -1.0) continue;
        ans.push_back({t.fi, t.se, i});
    }
    sort(ans.begin(), ans.end(), [](edge x, edge y) {
        if (x.a != y.a) return x.a > y.a;
        else if (x.b != y.b) return x.b < y.b;
        else return x.id < y.id;
    });
    if (ans.size() == 0) cout << "No Solution" << endl;
    else cout << mp[ans[0].id] << endl << lf(1) << ans[0].a << ' ' << lf(1) << ans[0].b << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}