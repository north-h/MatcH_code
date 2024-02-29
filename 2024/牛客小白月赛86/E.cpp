// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, W;
    cin >> n >> W;
    vector <int> w(n + 1), d(n + 1), sw(n + 1), sd(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sw[i] = sw[i - 1] + w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        sd[i] = sd[i - 1] + d[i];
    }
    vector <int> sdmx(n + 2);
    sdmx[n + 1] = -1e18;
    for (int i = n; i >= 1; i--) {
        sdmx[i] = max(sd[i], sdmx[i + 1]);
    }
    int res = -1e18;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, ans = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if (sw[mid] - sw[i - 1] >= W) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        if (ans != -1) res = max(res, sdmx[ans] - sd[i - 1]);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}