// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int k, l; cin >> k >> l;
    int mx = 0;
    for (int i = k; i >= 1; i --) {
        if (l - (1ll << i) >= 0) l -= (1ll << i), mx = max(mx, i);
    }
    if (l) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        cout << (1ll << mx) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}