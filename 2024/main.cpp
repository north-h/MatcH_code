// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    auto check = [&](int x) -> bool {
        int lst = 0;
        vector<int> s(21);
        for (int i = 1; i <= x; i ++) {
            lst |= a[i];
            for (int j = 0; j < 20; j ++) {
                s[j] += (a[i] >> j & 1);
            }
        }
        // debug2(x, lst);
        // for (int i = 0; i < 20; i ++) cout << s[i] << ' '; cout << '\n';
        for (int i = x + 1; i <= n; i ++) {
            for (int j = 0; j < 20; j ++) {
                s[j] -= (a[i - x] >> j & 1);
            }
            for (int j = 0; j < 20; j ++) {
                s[j] += (a[i] >> j & 1);
            }
            int sum = 0, p;
            for (int i = 19; i >= 0; i --) {
                if (s[i]) {
                    p = i;
                    break;
                }
            }
            for (int j = 0; j <= p; j ++) {
                if (s[j]) sum += ksm(2, j);
            }
            // debug1(sum);
            if (sum != lst) return false;
        }
        return true;
    };
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}