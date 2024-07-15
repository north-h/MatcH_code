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
    int  n, k; cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i ++) {
        int sum = i;
        double res = 1;
        while (sum < k) {
            sum *= 2;
            res *= 0.5;
        }
        ans += res / n;
    }
    cout << lf(10) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}