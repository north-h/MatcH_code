/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-10 21:38:56
 *
 * Problem: E. CHASE!
 * Contest: Codeforces - SMU Autumn 2024 Team Round 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/555870/problem/E
 * MemoryL: 256 MB
 * TimeL:   500 ms
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
    int n, k, Q; cin >> n >> k >> Q;
    vector<int> a(n + 1), s(n + 1);
    int cnt = n * (n - 1) / 2;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) cin >> a[i], mp[i] = a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    vector<double> dp(k + 1);
    dp[0] = s[n] * (n - 1) * 1.0 / cnt;
    // debug1(dp[0]);
    for (int i = 1; i <= k; i ++) {
        int c = 0, v = 0, l = 1;
        for (int r = n; r > l; r --) {
            while (l < r && a[l] + a[r] <= dp[i - 1]) l ++;
            if (l >= r) break;
            // debug2(l, r);
            c += (r - l);
            v += (r - l) * a[r] + s[r - 1] - s[l - 1];
        }
        // debug2(c, v);
        dp[i] = (dp[i - 1] * (cnt - c) + v) * 1.0 / cnt;
    }
    // for (int i = 1; i <= n; i ++) cout << s[i] << " \n"[i == n];
    // for (int i = 0; i <= k; i ++) cout << dp[k] << " \n"[i == k];
    cout << fixed << setprecision(9) << dp[k] << '\n';
    while (Q --) {
        int x, y, c; cin >> x >> y >> c;
        int cv = mp[x] + mp[y];
        // debug2(cv, dp[c - 1]);
        if (c == 0) cout << "accept\n";
        else if (abs(cv - dp[c - 1]) < 1e-4) cout << "both\n";
        else if (cv < dp[c - 1]) cout << "reselect\n";
        else cout << "accept\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}