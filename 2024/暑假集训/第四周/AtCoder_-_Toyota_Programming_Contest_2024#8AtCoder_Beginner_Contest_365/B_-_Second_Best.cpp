/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-03 20:00:19 ms
 *
 * Problem: B - Second Best
 * Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
 * URL:     https://atcoder.jp/contests/abc365/tasks/abc365_b
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a.begin() + 1, a.end());
    cout << mp[a[n - 1]] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}