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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = i, r = n, res = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if (a[mid] - a[i] <= k) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        if (res != -1) ans = max(ans, res - i + 1);
    }
    cout << lf(6) << ans * 1.0 / n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}