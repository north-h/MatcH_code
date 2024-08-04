// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, m;
int g[1010][1010], vis[1010][1010];
int ans, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<array<int, 2>> t;
bool ok;
set<array<int, 2>> st;

void dfs(int x, int y) {
	if (x == n && y == m) {
		for (auto [x, y] : t) st.insert({x, y});
		return ;
	}
	for (int i = 0; i < 4; i ++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
		if (vis[tx][ty] || g[tx][ty] == -1) continue;
		vis[tx][ty] = 1;
		t.push_back({tx, ty});
		dfs(tx, ty);
		t.pop_back();
		vis[tx][ty] = 0;
	}
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> g[i][j];
		}
	}
	// for (int i = 1; i <= n; i ++) {
	// 	for (int j = 1; j <= m; j ++) {
	// 		cout << g[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	vis[1][1] = 1;
	t.push_back({1, 1});
	dfs(1, 1);
	for (auto [x, y] : st) {
		// debug2(x, y);
		// debug1(g[x][y]);
		ans += g[x][y];
	}
	if (!st.size()) cout << -1 << '\n';
	else cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	// cin >> h_h;
	while (h_h--)solve();
	return 0;
}