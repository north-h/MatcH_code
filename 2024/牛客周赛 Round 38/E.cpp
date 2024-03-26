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

int c[N];

void solve() {
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 1, x; i <= n; i ++) {
		cin >> x;
		c[x] ++;
		mx = max(mx, c[x]);
	}
    for (int i  = 1; i <= N; i ++) {
        for (int j = 2; i * j <= N; j ++) {
            int cnt = 0;
            for (int k = i; k <= N; k *= j) {
                if (!c[k]) break;
                cnt ++;
            }
            mx = max(mx, cnt);
        }
    }
    cout << mx << endl;
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