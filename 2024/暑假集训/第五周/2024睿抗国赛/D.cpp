// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n, m, s, tt; cin >> n >> m >> s >> tt;
	vector<vector<array<int, 2>>> g(n + 1);
	vector<int> val(n + 1);
	for (int i = 1; i <= n; i ++) cin >> val[i];
	for (int i = 1; i <= m; i ++) {
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	// for (int i = 1; i <= n; i ++) {
	// 	cout << i << ":";
	// 	for (auto [x, y] : g[i]) cout << x << '|' << y << ' ';
	// 	cout << '\n';
	// }
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
	vector<int> vis(n + 1), dis(n + 1, INF);
	pq.push({0, val[s], s});
	dis[s] = 0;
	while (pq.size()) {
		auto t = pq.top();
		pq.pop();
		// debug1(t[2]);
		if (vis[t[2]]) continue;
		vis[t[2]] = 1;
		for (auto [v, w] : g[t[2]]) {
			if (dis[v] >= dis[t[2]] + w) {
				dis[v] = dis[t[2]] + w;
				// debug1(v);
				if (v == tt) {
					cout << dis[tt] << ' ' << t[1] << '\n';
					return ;
				}
				pq.push({dis[v], max(val[v], t[1]), v});
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	// cin >> h_h;
	while (h_h--)solve();
	return 0;
}