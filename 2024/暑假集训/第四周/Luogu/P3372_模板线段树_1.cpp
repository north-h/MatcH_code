/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-01 01:15:21
 *
 * Problem: P3372 【模板】线段树 1
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3372
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template<class T>
struct SegmentTree {
#define ls u << 1
#define rs u << 1 | 1
    struct Info {
        int l, r; 
        T sum, add;
    };
    vector<Info> tr;
};

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}