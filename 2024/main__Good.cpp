#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


void solve() {  //L
    int n; cin >> n;
    int l = 2025, r = 1e18, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int res = (mid - 2024) / 4;
        int sum1 = 1, sum2 = 4;
        for (int i = 1; i <= 9; i ++) {
            sum1 *= 100;
            res -= (mid - 2000) / sum1;
        }
        for (int i = 1; i <= 8; i ++) {
            sum2 *= 100;
            res += (mid - 2000) / sum2;
        }
        if ((mid - 2024) - res >= n) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int32_t main() {
//    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
