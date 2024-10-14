/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 12:34:33
 *
 * Problem: C. Social Distance
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/C
 * MemoryL: 256 MB
 * TimeL:   1500 ms
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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    if (n > m) {
        cout << "NO\n";
        return ;
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    int tp = 0;
    for (int i = 2; i <= n; i ++) {
        tp = tp + a[i - 1] + 1;
        if (tp > m - 1) {
            cout << "NO\n";
            return ;
        }
    }
    if (tp + a[1] > m - 1) {
        cout << "NO\n";
    } else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}