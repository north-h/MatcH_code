/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-26 10:28:49
 *
 * Problem: F. Custom-Made Clothes
 * Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
 * URL:     https://codeforces.com/gym/105143/problem/F
 * MemoryL: 1024 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

int n, k, x = n, y = 1;

int check(int res) {
    int ans = 0;
    for (int i = n, j = 1; i >= 1 && j <= n;) {
        cout << '?' << ' ' << i << ' ' << j << ' ' << res << endl;
        int c; cin >> c;
        if (c) ans += i, j ++;
        else i --;
    }
    // debug2(ans, n * n - k + 1);
    return ans >= k;
}

void solve() {
    cin >> n >> k;
    k = n * n - k + 1;
    int l = 1, r = n * n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << '!' << ' ' << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}