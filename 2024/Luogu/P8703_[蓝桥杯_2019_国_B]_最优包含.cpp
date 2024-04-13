/*
* =========================================================
* Author:  north_h
* Time:    2024-04-09 13:04:39 ms
*
* Problem: P8703 [蓝桥杯 2019 国 B] 最优包含
* Contest: Luogu
* URL:     https://www.luogu.com.cn/problem/P8703?contestId=166591
* MemoryL: 128 MB
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), p(11, 1);
    vector<array<ll, 11>> cnt(n + 1);
    for (int i = 1; i <= 9; i ++) p[i] = p[i - 1] * 10;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        for (int j = 1; j <= 9; j ++) {
            cnt[(a[i] * p[j]) % k][j] ++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x = a[i]
    }
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