/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-06 16:31:47
 *
 * Problem: A. Meaning Mean
 * Contest: Codeforces - Codeforces Round 977 (Div. 2, based on COMPFEST 16 - Final Round)
 * URL:     https://codeforces.com/contest/2021/problem/0
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    multiset<int> st;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        st.insert(x);
    }
    debug1(n);
    while (st.size() > 1) {
        auto v1 = *st.begin();
        st.erase(st.begin());
        auto v2 = *st.begin();
        st.erase(st.begin());
        st.insert((v1 + v2) / 2);
    }
    cout << (*st.begin()) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}