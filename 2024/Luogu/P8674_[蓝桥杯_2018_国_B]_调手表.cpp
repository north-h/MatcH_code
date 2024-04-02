/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:27 ms
 *
 * Problem: P8674 [蓝桥杯 2018 国 B] 调手表
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8674?contestId=165469
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * =========================================================
 */

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
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, k;
vector<int> g[N];
int d[N], vis[N];

void bfs(int u) {
    memset(d, 0x3f, sizeof d);
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    d[u] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (vis[i]) continue;
            d[i] = min(d[t] + 1, d[i]);
            q.push(i);
            vis[i] = 1;
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int a = (i + 1) % n;
        int b = (i + k) % n;
        g[i].push_back(a);
        g[i].push_back(b);
    }
    bfs(0);
    int ans = 0;
    for (int i = 0; i < n; i ++) ans = max(ans, d[i]);
    cout << ans << endl;
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