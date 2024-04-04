/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-04 09:03:58
 *
 * Problem: 约数的个数
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/3380/
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
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int res = 1;
    for (int i = 2; i <= n / i; i ++) {
        if (n % i != 0) continue;
        int cnt = 0;
        while (n % i == 0) n/= i, cnt ++;
        res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    cout << res << endl;
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