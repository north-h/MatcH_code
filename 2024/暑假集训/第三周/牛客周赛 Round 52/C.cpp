// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    int c1 = 0, c2 = 0, c0 = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (x < 0) c1 ++;
        else if (x == 0) c0 ++;
        else c2 ++;
    }
    if (n == 1) {
        cout << 1 << '\n';
        return ;
    }
    // debug2(c1, c2);
    // debug1(c0);
    int ans = n;
    if (c1 > c2) {
        c1 -= c2;
        ans -= c2 * 2;
        ans -= (c1 / 2) * 2;
        ans -= (c0 / 2) * 2;
        if (c1 & 1 && c0 & 1) ans -= 2;
    } else {
        ans -= c1 * 2;
        ans -= (c0 / 2) * 2;
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