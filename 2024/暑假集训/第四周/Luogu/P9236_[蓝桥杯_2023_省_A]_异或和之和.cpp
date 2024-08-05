/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-05 10:44:09 ms
 *
 * Problem: P9236 [蓝桥杯 2023 省 A] 异或和之和
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9236
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> pre(n + 1);
    int sum = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        pre[i] = pre[i - 1] ^ x;
        sum += x;
    }
    int ans = 0;
    for (int j = 0; j < 20; j ++) {
        int c[2] = {0, 0};
        for (int i = 0; i <= n; i ++) {
            c[pre[i] >> j & 1] ++;
        }
        ans += (1ll << j) * c[1] * c[0];
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}