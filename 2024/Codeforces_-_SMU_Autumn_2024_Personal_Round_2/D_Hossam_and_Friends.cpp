/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 14:22:54
 *
 * Problem: D. Hossam and Friends
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/D
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

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 1; i <= m; i ++) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        mp[r].push_back(l);
    }
    for (auto &[x, y] : mp) {
        sort(y.begin(), y.end());
    }
    int ans = 0, L = 0;
    for (int i = 1; i <= n; i ++) {
        if (!mp[i].size()) ans += (i - L);
        else {
            ans += (i - max(mp[i].back(), L));
            L = max(mp[i].back(), L);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}