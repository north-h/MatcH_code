/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:52 ms
 *
 * Problem: P8699 [蓝桥杯 2019 国 B] 排列数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8699?contestId=165868
 * MemoryL: 128 MB
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    int ans = 0;
    do {
        int c = 0;
        for (int i = 2; i < n; i ++) {
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                c ++;
        }
        if (c == k - 1) {
            ans ++;
        } else {
        }
    } while (next_permutation(a.begin() + 1, a.end()));
    cout << ans << endl;
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