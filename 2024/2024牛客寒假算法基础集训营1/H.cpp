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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
        if ((w[i] | m) == m) ans += v[i];
    }
    for (int i = 31; i >= 0; i --) {
        int sum = 0;
        if (m >> i & 1) {
            sum = (1 << i) - 1;
            sum |= (m - (1 << i));
        }
        int sv = 0, sw = 0;
        for (int j = 1; j <= n; j ++) {
            if ((w[j] | sum) == sum) {
                sv += v[j];
            }
        }
        ans = max(ans, sv);
    }
    cout << ans << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}