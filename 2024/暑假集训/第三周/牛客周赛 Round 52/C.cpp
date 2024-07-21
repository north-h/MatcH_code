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
    int c = 0;
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (x < 0) c ++;
        else mp[x] ++;
    }
    int ans = n;
    int cc = 0;
    for (auto [x, y] : mp) {
        ans -= (y / 2) * 2;
        cc += y % 2;
    }
    if (c >= cc) {
        ans -= cc * 2 + (c - cc) / 2 * 2;
    } else {
        ans -= c * 2;
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