/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:54
 *
 * Problem: G. Money Buys Less Happiness Now
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/G
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int m, x; cin >> m >> x;
    vector<int> cost(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> cost[i];
    }
    priority_queue<int> pq;
    int cur = 0, ans = 0;
    for (int i = 1; i <= m; i ++) {
        pq.push(cost[i]);
        cur += cost[i];
        if (cur <= (i - 1) * x) ans ++;
        else {
            cur -= pq.top();
            pq.pop();
        }
    }
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