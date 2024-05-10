// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define PII pair<int, int>
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) cin >> b[i];
    vector<int> c(1);
    map<int, double> mp;
    for (int i = 1; i <= k; i ++) {
        int x = a[i] - a[i - 1], y = b[i] - b[i - 1];
        c.push_back(a[i - 1] + 1);
        mp[a[i - 1] + 1] = x * 1.0 / y;
    }
    while (q --) {
        int x; cin >> x;
        if (x == 0) { cout << 0 << ' '; continue; }
        int l = 1, r = k, p = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (x >= c[mid]) l = mid + 1, p = mid;
            else r = mid - 1;
        }
        // debug1(p);
        int ans = b[p - 1] + (x - c[p] + 1) * 1.0 / mp[c[p]];
        cout << lf(0) << floor(ans) << ' ';
    }
    cout << '\n';
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