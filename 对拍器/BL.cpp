// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

struct node {
	double f = 0.0;
	int s = 0;
};

double calc(int x1, int y1, int x2, int y2) {
	return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
	int n, m, k, b, e, need;
	cin >> n >> m >> k >> b >> e;
	
	vector<array<double, 2>> loc(4), Stu(k);
	vector<array<double, 4>> w(k);
	
	for (auto &[x, y] : loc)
		cin >> x >> y;
	for (int c = 0; c < k; c ++) {
		int ex, ey; cin >> ex >> ey;
		int sx = loc[3][0], sy = loc[3][1];
		for (int i = 0; i < 4; i ++) w[c][i] = 1e15;
		for (int i = 0; i < 3; i ++) {
			w[c][1] = min(w[c][1], calc(ex, ey, loc[i][0], loc[i][1]) +
				calc(sx, sy, loc[i][0], loc[i][1]));
		}
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				if (i == j) continue;
				w[c][2] = min(w[c][2], calc(ex, ey, loc[i][0], loc[i][1]) +
					calc(loc[j][0], loc[j][1], loc[i][0], loc[i][1]) +
					calc(sx, sy, loc[j][0], loc[j][1]));
			}
		}
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				for (int k = 0; k < 3; k ++) {
					if (i == j || j == k || i == k) continue;
					w[c][3] = min(w[c][3], calc(ex, ey, loc[i][0], loc[i][1]) +
						calc(loc[j][0], loc[j][1], loc[i][0], loc[i][1]) +
						calc(sx, sy, loc[k][0], loc[k][1]) +
						calc(loc[j][0], loc[j][1], loc[k][0], loc[k][1]));
				}
			}
		}
	}
	
	// vector<array<int, 2>> T;
	
	// for (int i = 0; i < k; i ++) {
	//     for (int j = 1; j <= 3; j ++) {
	//         cout << w[i][j] << ' ';
	//     }
	//     cout << '\n';
	// }
	
	need = max((n + b - 1) / b, (m + e - 1) / e);
	vector<double> dp(need + 1, 1e15);
	
	dp[0] = 0;
	for (int i = 0; i < k; i ++) {
		for (int x = need; x >= 1; x --) {
			for (int j = 1; j <= min(k, 3); j ++) {
				dp[x] = min(dp[x], dp[x - j] + w[i][j]);
			}
		}
	}
	
	// debug1(need);
	cout << lf(10) << dp[need] << '\n';
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


