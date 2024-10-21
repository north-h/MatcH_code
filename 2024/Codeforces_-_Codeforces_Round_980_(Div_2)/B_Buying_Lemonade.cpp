/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-21 21:39:21
 *
 * Problem: B. Buying Lemonade
 * Contest: Codeforces - Codeforces Round 980 (Div. 2)
 * URL:     https://codeforces.com/contest/2024/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] * (n - i + 1) >= k) {
            ans += k;
            break;
        } else {
            k -= a[i];
            ans += a[i] + 1;
        }
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