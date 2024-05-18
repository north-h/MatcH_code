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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    set<array<int, 2>> st;
    for (int i = 1; i <= n; i ++) {
        if (a[i] != b[i]) {
            int x = i, y = mp[b[i]];
            st.insert({x, y});
            swap(mp[a[i]], mp[b[i]]);
            swap(a[x], a[y]);
        }
    }
    int m, c = 0; cin >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        if (st.count({x, y})) c ++;
    }
    if (m < st.size()) cout << "No" << '\n';
    else cout << "Yes" << '\n';
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