/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-21 20:56:28
 *
 * Problem: E. Relearn through Review
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/E
 * MemoryL: 1024 MB
 * TimeL:   3000 ms
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
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) pre[i] = __gcd(pre[i - 1], a[i]);
    for (int i = n; i >= 1; i --) suf[i] = __gcd(suf[i + 1], a[i]);
    int ans = pre[n];
    for (int i = 1; i <= n; i ++) {
        if (pre[i] == pre[i - 1]) continue;
        int gc = 0;
        for (int j = i; j <= n; j ++) {
            gc = __gcd(gc, a[j] + k);
            ans = max(ans, __gcd(pre[i - 1], __gcd(suf[j + 1], gc)));
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