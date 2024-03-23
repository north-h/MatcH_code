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
//  #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n, m, t;
	cin>> n >> m >> t;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	vector<PII> T(t + 1);
	for (int i = 1; i <= t; i ++) {
		T[i].fi = INF;
		T[i].se = 0;
	}
	for (int i = 1; i <= m; i ++) {
		vector<int> ve(t + 1);
		for (int j = 1; j <= n; j ++) {
			ve[a[j][i]] ++;
		}
		for (int j = 1; j <= t; j ++) {
			T[j].fi = min(T[j].fi,ve[j]);
			T[j].se = max(T[j].se,ve[j]);
		}
	}
	for (int i = 1; i <= t; i ++) cout << T[i].fi << ' ' << T[i].se << endl;
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