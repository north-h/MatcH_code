/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-10-14 23:25:27
 *
 * Problem: D. Attribute Checks
 * Contest: Codeforces - Educational Codeforces Round 170 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/2025/problem/D
 * MemoryL: 512 MB
 * TimeL:   2500 ms
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
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    for (auto &x : r) cin >> x;
    vector<int> S, I;
    for (int x : r) {
        if (x < 0) {
            S.emplace_back(-x);
        }
        else if (x > 0) {
            I.emplace_back(x);
        }
    }
    sort(S.begin(), S.end());
    sort(I.begin(), I.end());
    // Function to count number of elements <= val
    auto cnt_le = [&](const vector<int> &v, int val) -> int{
        return upper_bound(v.begin(), v.end(), val) - v.begin();
    };
    int mx = 0;
    for (int s = 0; s <= m; s++) {
        int i = m - s;
        if (i < 0) continue;
        int cs = cnt_le(S, s);
        int ci = cnt_le(I, i);
        mx = max(mx, cs + ci);
    }
    cout << mx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}