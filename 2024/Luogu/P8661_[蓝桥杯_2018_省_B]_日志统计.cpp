/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:39 ms
 *
 * Problem: P8661 [蓝桥杯 2018 省 B] 日志统计
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8661?contestId=165868
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    map<int, int> mp;
    vector<PII> tz(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> tz[i].fi >> tz[i].se;
    }
    sort(tz.begin() + 1, tz.end());
    set<int> st;
    deque<PII> dq;
    for (int i = 1; i <= n; i ++) {
        while (dq.size() && tz[i].fi - dq.front().fi >= d) {
            mp[dq.front().se] --;
            dq.pop_front();
        }
        dq.push_back(tz[i]);
        mp[tz[i].se] ++;
        if (mp[tz[i].se] >= k) st.insert(tz[i].se);
    }
    for (auto i : st) cout << i << endl;
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