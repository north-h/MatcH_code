// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> s(n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	int ans = -1e18;
	for (int i = 1; i + k * 2 - 1 <= n; i++) {
		ans = max(ans, s[i + k * 2 - 1] - s[i - 1]);
	}
	int l, r;
	int res1 = -1e18, res2 = -1e18;
	for (int i = 1; i + k - 1 <= n; i++) {
		if(s[i + k - 1] - s[i - 1] > res1){
			res1 = s[i + k - 1] - s[i - 1];
			l = i;
			r = i + k - 1;
		}
	}
	// debug2(l, r);
	for (int i = 1; i + k - 1 <= n; i++) {
		if(i >= l && i <= r || i + k - 1 >= l && i + k - 1 <= r) continue;
		// debug2(i, i + k - 1);
		res2 = max(res2, s[i + k - 1] - s[i - 1]);
	}
//	 debug2(res1, res2);
	cout << max(ans, res1 + res2) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int h_h = 1;
	cin >> h_h;
	while (h_h--)solve();
	return 0;
}