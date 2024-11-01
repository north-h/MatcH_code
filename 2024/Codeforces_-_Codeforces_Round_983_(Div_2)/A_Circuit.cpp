/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-01 22:36:05
 *
 * Problem: A. Circuit
 * Contest: Codeforces - Codeforces Round 983 (Div. 2)
 * URL:     https://codeforces.com/contest/2032/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    int cnt = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cnt++;
        }
    }
    int mn = 0;
    if (cnt % 2) mn = 1;
    int mx = min(cnt, n * 2 - cnt);

    cout << mn << " " << mx << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}