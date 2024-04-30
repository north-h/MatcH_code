/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-30 10:57:30 ms
 *
 * Problem:  The Great Mixing
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-788C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * =========================================================
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
    int n, k; cin >> n >> k;
    vector<int> d(2010, -1);
    queue<int> q;
    for (int i = 1, x; i <= k; i ++) {
        cin >> x;
        x = x - n + 1000;
        d[x] = 1;
    }
    for (int i = 0; i <= 2000; i ++) {
        if (d[i] == 1)q.push(i);
    }
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i <= 2000; i ++) {
            auto u = t + i - 1000;
            if (u < 0 || u > 2000) continue;
            if (d[i] != 1 || d[u] != -1) continue;
            d[u] = d[t] + 1;
            q.push(u);
        }
    }
    cout << d[1000] << '\n';
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