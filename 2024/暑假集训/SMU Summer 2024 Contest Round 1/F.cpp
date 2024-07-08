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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector <array<int, 2>> b(m + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int j = 1; j <= m; j ++) {
        cin >> b[j][1] >> b[j][0];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    for (int i = 1, j = m; i <= n && j >= 1; i ++) {
        if (b[j][0] <= a[i]) break;
        if (b[j][1]) {
            b[j][1] --;
            a[i] = b[j][0];
        } else {
            j --;
            if (b[j][0] <= a[i]) break;
            b[j][1] --;
            a[i] = b[j][0];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += a[i];
    }
    // for (auto [x, y] : b) cout << x << ' ' << y << '\n';
    // for (int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}