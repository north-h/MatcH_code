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

void solve(int t) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    vector<pair<double, int>> b(n + 1);
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].second;
        int l = 1, r = a[i].first, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (mid * (mid + 1) >= a[i].first * 2) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        b[i].first = a[i].second * 1.0 / res;
        b[i].second = res;
    }
    sort(b.rbegin() + 1, b.rend());
    for (auto [x, y] : a) cout << x << ' ' << y << '\n';
    for (int i = 1; i <= n; i ++) {
        ans += sum * b[i].second;
        sum -= a[i].second;
    }
    cout << "Case #" << t << ": " << ans << '\n';
}


int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    for (int i = 1; i <= h_h; i ++) solve(i);
    return 0;
}