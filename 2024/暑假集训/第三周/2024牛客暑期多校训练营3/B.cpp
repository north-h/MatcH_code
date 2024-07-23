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
    int n, d; cin >> n >> d;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = INF;
    for (int i = n; i >= 1; i --) {
        if (d >= a[i]) {
            int x = d / a[i] * a[i];
            d -= x;
            ans = min(ans, d);
        }
    }
    debug1(d);
    for (int i = n; i >= 1; i --) {
        if (d >= a[i]) {
            int x = d / a[i] * a[i];
            d -= x;
        }
    }
    ans = min(ans, d);
    for (int i = n; i >= 1; i --) {
        if (a[i] < d) continue;
        int dd = a[i] - d;
        debug1(dd);
        for (int j = n; j >= 1; j --) {
            if (dd >= a[j]) {
                int x = dd / a[j] * a[j];
                dd -= x;
            }
        }
        ans = min(ans, dd);
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