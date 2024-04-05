/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-05 10:39:52
 *
 * Problem: 阶乘分解
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/199/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

int vis[N];

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int x = 2; x <= n; x ++) {
        int y = x; 
        if (!vis[x]) {
            mp[x] ++;
            continue;
        }
        for (int i = 2; i <= y / i; i ++) {
            if (y % i != 0) continue;
            int cnt = 0;
            while (y % i == 0) y /= i, mp[i] ++;
        }
        if (y > 1) mp[y] ++;
    }
    for (auto [x, y] : mp) cout << x << ' ' << y << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i]) continue;
        for (int j = i + i; j < N;j ++) {
            vis[j] = 1;
        }
    }
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}