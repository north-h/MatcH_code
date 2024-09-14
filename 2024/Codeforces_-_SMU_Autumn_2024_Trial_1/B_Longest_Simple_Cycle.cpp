/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-09 14:27:57
 *
 * Problem: B. Longest Simple Cycle
 * Contest: Codeforces - SMU Autumn 2024 Trial 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548611/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-09 14:27:57
 *
 * Problem: B. Longest Simple Cycle
 * Contest: Codeforces - SMU Autumn 2024 Trial 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548611/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    vector<int> dp(n + 1);
    int ans  = 0;
    for (int i = 2; i <= n; i ++) {
        if (a[i] == b[i]) {
            dp[i] = abs(a[i] - b[i]) + 1 + c[i];
        } else {
            dp[i] = c[i] + 1 + max(dp[i - 1] - abs(a[i] - b[i]), abs(a[i] - b[i]));
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}