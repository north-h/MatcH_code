/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-28 08:48:53
 *
 * Problem: A. Card Exchange
 * Contest: Codeforces - Codeforces Round 941 (Div. 2)
 * URL:     https://codeforces.com/contest/1966/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

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

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x; mp[x] ++;
    }
    vector<int> t;
    for (auto [x, y] : mp) t.push_back(y);
    sort(t.rbegin(), t.rend());
    int ans = 0, sum = 0;
    for (int i = 0; i < t.size(); i ++) {
        if (t[i] >= k) {
            t[i] = 0;
            sum += k - 1;
        } else if (k - t[i] <= sum) {
            sum -= (k - t[i]);
            sum += k - 1;
            t[i] = 0;
        }
    }
    ans = min(sum, k - 1);
    for (auto i : t) ans += i;
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