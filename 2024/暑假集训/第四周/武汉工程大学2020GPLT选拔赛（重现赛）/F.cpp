// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
    if (sum < m) {
        cout << 0 << '\n';
        return ;
    }
    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            cnt += a[i] / x;
        }
        return cnt >= m;
    };
    int l = 1, r = sum / n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
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