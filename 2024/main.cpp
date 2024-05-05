// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    map<int, set<int>> mp;
    for (int i = 1; i <= m; i ++) {
        int a, b; cin>> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    for (int i = 2; i < n; i ++) {
        if (mp[1].count(i) && mp[i].count(n)) {
            cout << "POSSIBLE" << '\n';
            return ;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
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