// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int n, k; cin >> n >> k;
    vector<double> cc;
    for (int i = 1; i <= n; i ++) {
        int x, y, R; cin >> x >> y >> R;
        double d = max(R - sqrt(x * x + y * y), 0.0);
        cc.push_back(acos(-1) * R * R * d);
    }
    sort(cc.begin(), cc.end());
    // for (auto i : cc) cout << i << ' ';
    // cout << '\n';
    double ans = 0;
    for (int i = 0; i < n - k; i ++) ans += cc[i];
    cout << fixed << setprecision(20) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}