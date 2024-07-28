// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int sum = pre[n];
    for (int i = n; i >= 1; i --) {
        suf[i] = min(suf[i + 1] + a[i], (n - i + 1) * r);
    }
    int ans = pre[n];
    for (int i = 0; i <= n; i ++) {
        ans = min(ans, min(pre[i], i * l) + suf[i + 1]);
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