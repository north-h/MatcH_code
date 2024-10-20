/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-19 12:32:07
 *
 * Problem: B. Gold Medal
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/B
 * MemoryL: 1024 MB
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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    int ans = 0;
    vector<int> t;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans += a[i] / k;
        t.push_back((a[i] + k - 1) / k * k - a[i]);
    }
    int m; cin >> m;
    sort(t.begin(), t.end());
    for (auto i : t) {
        if (!i) continue;
        if (i > m) break;
        ans ++;
        m -= i;
    }
    cout << ans + m / k << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}