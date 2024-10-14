/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-10-14 23:10:35
 *
 * Problem: C. New Game
 * Contest: Codeforces - Educational Codeforces Round 170 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/2025/problem/C
 * MemoryL: 512 MB
 * TimeL:   2000 ms
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<pair<int, int>> v;
    int c = 1, num = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == num) c++;
        else {
            v.push_back({num, c});
            num = a[i];
            c = 1;
        }
    }
    v.push_back({num, c});
    int m = v.size();
    int s = 0, ans = 0;
    for (int r = 0, l = 0; r < m; r++) {
        s += v[r].second;
        while ( (v[r].first - v[l].first > (r - l)) || (r - l + 1 > k)) {
            s -= v[l].second;
            l++;
        }
        ans = max(ans, s);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}