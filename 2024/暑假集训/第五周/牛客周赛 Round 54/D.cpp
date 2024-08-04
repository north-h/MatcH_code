// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (a[i] % j == 0) {
				if (i + j <= n) g[i].push_back(i + j);
				if (i - j >= 1) g[i].push_back(i - j);
			}
		}
	}
	queue<int> q;
	q.push(1);
	vector<int> vis(n + 1), dis(n + 1);
	dis[1] = 0;
	vis[1] = 1;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		for (auto v : g[t]) {
			if (vis[v]) continue;
			dis[v] = dis[t] + 1;
			q.push(v);
			vis[v] = 1;
		}
	}
	cout << dis[n] << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	// cin >> h_h;
	while (h_h--)solve();
	return 0;
}