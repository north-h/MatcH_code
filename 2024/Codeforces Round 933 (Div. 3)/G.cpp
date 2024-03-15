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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int idx= n + 1;
    vector<vector<PII>> g(n + m + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!mp.count(c)) mp[c] = idx ++;
        g[a].push_back({mp[c], 1});
        g[b].push_back({mp[c], 1});
        g[mp[c]].push_back({b, 0});
        g[mp[c]].push_back({a, 0});
    }
    int s, e;
    cin >> s >> e;
    deque<int> dq;
    vector<int> d(n + m + 1, INF);
    d[s] = 0;
    dq.push_front(s);
    while (dq.size()) {
        auto t = dq.front();
        dq.pop_front();
        for (auto [x, y] : g[t]) {
            if (d[x] != INF) continue;
            d[x] = min(d[x], d[t] + y);
            if (y == 0) dq.push_front(x);
            else dq.push_back(x);
        }
    }
    cout << d[e] << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}