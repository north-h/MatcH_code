// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    if (x == 0) {cout << 0 << '\n';return ;}
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int y; cin >> y;
        if (x == 0) break;
        else if (x > 0) x -= y;
        else x += y;
        ans += abs(y);
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