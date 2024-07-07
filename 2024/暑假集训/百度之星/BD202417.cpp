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
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    ll li, ri, c, ans = -1; cin >> li >> ri >> c;
    auto check = [&](ll x) -> bool{
        ll cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (b[i] < li) {
                ll xy = (li - b[i] + a[i] - 1) / a[i] * a[i];
                ll y = b[i] + xy;
                cnt += (max(0ll, x - y + 1) + a[i] - 1) / a[i];
            } else cnt += (max(0ll, x - b[i] + 1) + a[i] - 1) / a[i];
        }
        return cnt >= c;
    };
    ll l = li, r = ri;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
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