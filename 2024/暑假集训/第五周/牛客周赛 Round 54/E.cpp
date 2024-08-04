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
	vector<int> len(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> len[i];
	}
	vector<int> dp(n + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = n; j >= len[i]; j --) {
			if (dp[j - len[i]] != INF) {
				if (i > j - len[i] && i <= j)
					dp[j] = min(dp[j], dp[j - len[i]] + 1);
			}
		}
	}
	if (dp[n] == INF) cout << -1 << '\n';
	else cout << dp[n] << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	cin >> h_h;
	while (h_h--)solve();
	return 0;
}