/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 12:44:11
 *
 * Problem: C. Pleasant Pairs
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;
const int mod = 998244353;

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

bool check(int x) {
    int y = (int) sqrt(x);
    return x == y * y;
}

void solve() {
    int n, m; cin >> n >> m;
    set<array<int, 2>> st;
    for (int i = 1; i <= m; i ++) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        st.insert({l, r});
    }
    auto check = [&](int l, int r) -> bool {
        for (int i = l; i <= r; i ++) {
            for (int j = i; j <= r; j ++) {
                // debug2(i, j);
                if (st.count({i, j})) return false;
            }
        }
        return true;
    };
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            if (check(i, j)) ans ++;
        }
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