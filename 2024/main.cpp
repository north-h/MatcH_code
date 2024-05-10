// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 8 << '\n';
        return ;
    }
    if (n == 2) {
        cout << 16 << '\n';
        return ;
    }
    int l = 0, r = n, ans = 0;
    auto check = [&](int x) -> bool {
        int y = x * x + n * n;
        return y < (n + 1) * (n + 1);
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    debug1(ans);
    int c = ceil(n * 1.0 / sqrt(2));
    l = ceil(n * 1.0 / sqrt(2)), r = n;
    int res = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid * sqrt(2) < n + 1) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    debug2(res, c);
    int v = ans * 2;
    if (res != -1) v += (res - c + 1);
    cout << v * 4 + 4 << '\n';
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