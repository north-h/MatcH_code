// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i ++) cin >> a[i] >> b[i];
    int k; cin >> k;
    vector<int> c(k + 1), d(k + 1);
    for (int i = 1; i <= k; i ++) cin >> c[i] >> d[i];
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 0; i < (1 << k); i ++) {
        vector<int> cnt(n + 1);
        for (int j = 0; j < k; j ++) {
            // debug2(c[j], d[j]);
            if (i >> j & 1) cnt[c[j + 1]] ++;
            else cnt[d[j + 1]] ++;
        }
        // for (int j = k - 1; j >= 0; j --) {
        //     cout << (i >> j & 1) << ' ';
        // }
        // cout << '\n';
        int res = 0;
        for (int j = 1; j <= m; j ++) {
            if (cnt[a[j]] && cnt[b[j]]) res ++;
        }
        // debug2(i, res);
        // for (int i = 1; i <= n; i ++) cout << cnt[i] << ' ';
        // cout << '\n';
        ans = max(ans, res);
        // cout << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}