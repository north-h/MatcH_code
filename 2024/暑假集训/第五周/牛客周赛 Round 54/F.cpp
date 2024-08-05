// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
int g[1010][1010], lj[1010][1010];
int ans, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<array<int, 2>> q;
unordered_map<int, unordered_map<int, int>> vis;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i ++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 1 || ty < 1 || tx > n || ty > m || vis[tx][ty] || g[tx][ty] == -1) continue;
		vis[tx][ty] = 1;
		dfs(tx, ty);
		if (lj[tx][ty]) {
			lj[x][y] = 1;
			q.push({tx, ty});
		}
	}
}


void dfs1(int x, int y) {
	for (int i = 0; i < 4; i ++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
		if (vis[tx][ty] || g[tx][ty] == -1) continue;
		if (!lj[tx][ty]) {
			vis[tx][ty] = 1;
			dfs1(tx, ty);
		}
		if (lj[tx][ty] && lj[x][y] != 2) {
			lj[x][y] = 1;
			q.push({x, y});
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> g[i][j];
		}
	}
	lj[n][m] = 1;
	vis[1][1] = 1;
	dfs(1, 1);
	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();
		lj[x][y] = 2;
		vis.clear();
		vis[x][y] = 1;
		dfs1(x, y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (lj[i][j]) {
				ans += g[i][j];
			}
		}
	}
	if (!lj[1][1]) ans = 0;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	// cin >> h_h;
	while (h_h--)solve();
	return 0;
}