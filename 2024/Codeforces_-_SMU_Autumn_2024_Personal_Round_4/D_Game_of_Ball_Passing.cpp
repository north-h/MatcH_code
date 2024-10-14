/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 13:02:04
 *
 * Problem: D. Game of Ball Passing
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/D
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
    vector<int> a(n + 1);
    map<int, int> mp; int s = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] ++, s += a[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    if (mp.size() == 1 && a[1] == 0) {
        cout << 0 << '\n';
        return ;
    }
    // s -= a[1];
    // int sum = a[1], c = a[1];
    // for (int i = 2; i <= n; i ++) {
    //     if (sum >= a[i]) sum -= a[i], c = i;
    //     else sum = a[i] - sum;
    // }
    if (a[1] <= s / 2) {
        cout << 1 << '\n';
        return ;
    }
    // debug2(sum, c);
    cout << a[1] * 2 - s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}