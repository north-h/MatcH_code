/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-25 15:52:02
 *
 * Problem: D. DiviDuelo
 * Contest: Codeforces - SMU Autumn 2024 Team Round 3（成都）
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/552299/problem/D
 * MemoryL: 1024 MB
 * TimeL:   300 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> st;
    for (int i = 1; i <= n / i; i ++) {
        if (n % i) continue;
        st.insert(i);
        st.insert(n / i);
    }
    int sz = st.size();
    // cout << sz << '\n';
    // for (auto i : st) cout << i << ' ';
    // cout << '\n';
    if (sz & 1) {
        cout << "N\n";
        return ;
    }
    if (sz <= 4) {
        cout << "Y\n";
        return ;
    }
    int gc = 0;
    for (auto i : st) {
        if (i == 1) continue;
        gc = gcd(i, gc);
    }
    cout << (gc == 1 ? "N" : "Y") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}