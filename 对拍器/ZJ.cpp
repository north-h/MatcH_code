#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

double calc(array<int, 2> &x, array<int, 2> &y) {
	return sqrt(1.0 * (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int b, e;
	cin >> b >> e;
	
	vector<array<int, 2>> loc(4), Stu(k);
	for (auto &[x, y] : loc)
		cin >> x >> y;
	for (auto &[x, y] : Stu)
		cin >> x >> y;
	
	vector<vector<int>> lu{
		{3},
		{0, 3}, {1, 3}, {2, 3},
		{0, 1, 3}, {0, 2, 3},
		{1, 0, 3}, {1, 2, 3},
		{2, 0, 3}, {2, 1, 3},
		{0, 1, 2, 3}, {0, 2, 1, 3},
		{1, 0, 2, 3}, {1, 2, 0, 3},
		{2, 0, 1, 3}, {2, 1, 0, 3},
	};
	int idx = 0;
	vector res(k, vector<double>(4, 1e11));
	for (auto &pos : Stu) {
		for (int i = 0; i < 16; i ++) {
			double sum = 0;
			auto last = pos;
			int s = lu[i].size() - 1;
			for (auto j : lu[i]) {
				sum += calc(last, loc[j]);
				last = loc[j];
			}
			res[idx][s] = min(res[idx][s], sum);
		}
		idx ++;
	}
	
	for (int i = 0; i < k; i ++) {
		for (int j = 1; j <= 3; j ++) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	
	const int need = max((n + b - 1) / b, (m + e - 1) / e);
	
	vector<double> dp(need + 1, 1e9);
	dp[0] = 0;
	for (int i = 0; i < res.size(); i ++) {
		for (int k = need; k >= 1; k --)  
			for (int j = 0; j <= min(3, k); j ++)
				dp[k] = min(dp[k], dp[k - j] + res[i][j]);
	}
	
	printf("%.10lf\n", dp[need]);
	
	return 0;
}
