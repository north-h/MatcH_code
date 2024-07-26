// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int get(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int a, b, x; cin >> a >> b >> x;
    int ans = 0;
    int p = 1;
    for (int i = 1; i <= 10; i ++) {
        if (i >= 2) p *= 10;
        int y = x - b * i;
        int l = p, r = 1e9, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (get(mid) == i && a * mid + b * i <= x) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        ans = max(ans, res);
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