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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] -= i;
    }
    // for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
    // cout << '\n';
    auto check = [&](int b) -> int {
        int res = 0;
        for (int i = 1; i <= n; i ++) res += abs(a[i] - b);
        return res;
    };
    int l = -1e10, r = 1e10, ans = -1;
    while (l <= r) {
        int midl = l + (r - l) / 3;
        int midr = r - (r - l) / 3;
        int mid = (midr + midl) / 2;

        int ls = check(midl), rs = check(midr);
        // debug2(l, r);
        // debug2(midl, midr);
        // debug2(ls, rs);
        if (ls <= rs) r = midr - 1;
        else l = midl + 1;
    }
    cout << check(l) << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}