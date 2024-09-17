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
    set<int> st;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        ta.push_back(x);
        st.insert(x);
    }
    sort(ta.begin(), ta.end());
    while (q --) {
        int t; cin >> t;
        if (st.count(t)) {
            cout << 0 << '\n';
            continue;
        }
        if (t < ta[0]) {
            int ans = t - 1, x = ta[0] - ans - 2;
            ans += x + 1;
            cout << ans << '\n';
            continue;
        }
        if (t > ta[m - 1]) {
            int ans = n - t, x = n - 1 - (ta[m - 1] + ans);
            ans += x + 1;
            cout << ans << '\n';
            continue;
        }
        auto p = lower_bound(ta.begin(), ta.end(), t) - ta.begin();
        // debug1(p);
        cout << (ta[p] - ta[p - 1]) / 2 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}