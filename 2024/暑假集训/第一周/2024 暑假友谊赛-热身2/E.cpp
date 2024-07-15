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
    int r, g, b, n; cin >> r >> g >> b >> n;
    set<array<int, 3>> st;
    int ans = 0;
    for (int i = 0; i <= 3000; i ++) {
        for (int j = 0; j <= 3000; j ++) {
            if (i * r + j * g > n) continue;
            int k = n - i * r - j * g;
            if (k % b == 0) ans ++;
        }
    }
    // cout << st.size() << '\n';
    // for (auto [x, y, z] : st) cout << x << ' ' << y << ' ' << z << '\n';
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}