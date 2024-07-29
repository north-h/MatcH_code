#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1 = -x1;
    double ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    x1 = -x1;
    y1 = -y1;
    ans = min(ans, sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    cout << lf(11) << ans << '\n';
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