/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-03 10:26:55 ms
 *
 * Problem: 小国王
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/1066/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

int n, k;
int dp[12][144][1 << 12];
    
void solve() {
    cin >> n >> k;
    vector<int> state(n + 1);
    map<int, int> sum;
    for (int i = 0; i < (1 << n); i ++) {
        if (!(i & (i >> 1))) {
            state.push_back(i);
            sum[i] = __builtin_popcount(i);
            debug2(i, sum[i]);
        }
    }
    int cnt = state.size();
    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i ++) {
        for (int j = 0; j <= k; j ++) {
            for (int now = 0; now < cnt; now ++) {
                for (int lst = 0; lst < cnt; lst ++) {
                    int c = sum[state[now]];
                    // if (j < c) continue;
                    // if ((state[now] & state[lst])) continue;
                    // if ((state[now >> 1] & state[lst])) continue;
                    // if ((state[now << 1] & state[lst])) continue;
                    // dp[i][j][now] += dp[i - 1][j - c][lst];
                    if (j >= c && !(state[now] & state[lst]) && !(state[now << 1] & state[lst]) && !(state[now >> 1] && state[lst])) {
                        dp[i][j][now] += dp[i - 1][j - c][lst];
                    }
                }
            }
        }
    }
    cout << dp[n + 1][k][0] << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}