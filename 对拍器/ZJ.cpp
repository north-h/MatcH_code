// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> ta;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        ta.push_back(x);
    }
    sort(ta.begin(), ta.end());
    int t; cin >> t;
    for (auto i : ta) {
        if (i == t) {
            cout << 10 << '\n';
            return ;
        }
    }
    if (t < ta[0]) {
        int ans = t - 1, x = ta[0] - ans - 2;
        ans += x + 1;
        cout << ans << '\n';
        return;
    }
    if (t > ta[m - 1]) {
        int ans = n - t, x = n - 1 - (ta[m - 1] + ans);
        ans += x + 1;
        cout << ans << '\n';
        return;
    }
    for (int i = 1; i < m; i ++) {
        if (t >= ta[i - 1] && t <= ta[i]) {
            cout << (ta[i] - ta[i - 1]) / 2 << '\n';
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}