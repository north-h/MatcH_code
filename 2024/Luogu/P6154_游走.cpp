/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 15:23:32
 *
 * Problem: P6154 游走
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P6154
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, mod = 1e9 + 7;

using namespace std;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    cout << ksm(2, 2) << '\n';
    for (int i = 1; i <= 1000; i ++) {
        for (int j = 1; j <= 1000; j ++) {
            if (i * ksm(j, mod - 2) % mod == 199648871) {
                cout << i << ' ' << j << '\n';
                return ;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}