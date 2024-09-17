/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-16 20:14:13
 *
 * Problem: J. Keyi LIkes Reading
 * Contest: Codeforces - SMU Autumn 2024 Team Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/550260/problem/J
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n, W; cin >> n >> W;
    map<int, int> cnt;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        cnt[x - 1] ++;
    }
    vector<int> t;
    for (auto [x, y] : cnt) t.push_back(y);
    vector<array<int, 2>> TxT;
    int m = (int)t.size();
    for (int i = 0; i < (1 << m); i ++) {
        int sum = 0;
        for (int j = 0; j < m; j ++) {
            if ((i >> j & 1)) sum += t[j];
        }
        if (sum <= W) TxT.push_back({sum, i});
    }
    vector<int> dp(1 << m + 1, INF), lf(1 << m + 1, W);
    dp[0] = 1;
    for (int i = 0; i < 1 << m; i ++) {
        for (auto [sum, st] : TxT) {
            int nst = i | st;
            if (sum <= lf[i]) {
                if (dp[nst] > dp[i]) {
                    dp[nst] = dp[i];
                    lf[nst] = lf[i] - sum;
                }
            } else if (dp[nst] > dp[i] + 1) {
                dp[nst] = dp[i] + 1;
                lf[nst] = W - sum;
            }
        }
    }
    cout << dp[(1 << m) - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}