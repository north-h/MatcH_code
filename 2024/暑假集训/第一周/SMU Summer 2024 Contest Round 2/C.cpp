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
    int n, m; cin >> n >> m;
    vector<int> L(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) cin >> L[i], L[i] ++;
    // sort(L.begin() + 1, L.end());
    // for (int i = 1; i <= n; i ++) cout << L[i] << ' ';
    // cout << '\n';
    auto check = [&](int x) -> bool {
        int W = 0, res = 0;
        // if (L.back() > x) return false;
        for (int i = 1; i <= n; i ++) {
            W += L[i];
            if (W - 1 > x) {
                W = L[i];
                res ++;
            }
            if (L[i] > x) return false;
        }
        if (W) res ++;
        return res <= m;
    };
    int l = 1, r = 1e15, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        // debug2(l, r);
        // debug1(mid);
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
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