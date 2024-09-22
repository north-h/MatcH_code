/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 12:44:11
 *
 * Problem: C. Pleasant Pairs
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 200010, INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

int up[N];

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        up[a[i]] = i;
    }
    int ans = 0;
    for (int i = 3; i < n * 2; i ++) {
        int x = i;
        for (int j = 1; j <= x / j; j ++) {
            if (x % j == 0 && j != x / j) {
                if (up[j] == 0 || up[x / j] == 0 || up[j] + up[x / j] != x) continue;
                ans ++;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        up[a[i]] = 0;
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