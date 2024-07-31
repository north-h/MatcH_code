// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b, c, n, w; cin >> a >> b >> c >> n >> w;
    int ans = 1e15;
    // for (int x = 0; x * a <= w && x <= n; x ++) {
    //     for (int y = 0; x * a + y * b <= w && x + y <= n; y ++) {
    //         int z = n - x - y;
    //         // if (z < 0) continue;
    //         ans = min(ans, abs(x * a + y * b + c * z - w));
    //     }
    // }
    for (int x = 0;  x <= n; x ++) {
        for (int y = 0;  x + y <= n; y ++) {
            for (int z = 0; x + y + z <= n; z ++) {
                if (x + y + z == n) ans = min(ans, abs(x * a + y * b + c * z - w));
            }
        }
    }
    // if (a <= b && a <= c) {
    //     ans = min(ans, abs(a * n - w));
    // } else if (b <= a && b <= c) {
    //     ans = min(ans, abs(b * n - w));
    // } else {
    //     ans = min(ans, abs(c * n - w));
    // }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}