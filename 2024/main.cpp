// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
#define PII pair<int, int>
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m + 1), x(m + 1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= m; i ++) {
        cin >> x[i];
        pq.push({x[i], i});
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        auto [val, id] = pq.top();
        pq.pop();
        ans += val;
        mp[id] ++;
        if (mp[id] == a[id]) continue;
        int nval = ((val + k) | (val & k));
        pq.push({nval, id});
    }
    cout << ans << '\n';
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