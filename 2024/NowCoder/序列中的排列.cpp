/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-11 19:00:35
 *
 * Problem: 序列中的排列
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/91355/A
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
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
    int n, k; cin >> n >> k;
    set<int> st;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        st.insert(x);
    }
    for (int i = 1; i <= k; i ++) {
        if (!st.count(i)) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}