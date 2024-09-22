/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-22 12:16:49
 *
 * Problem: A. Not Adjacent Matrix
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551809/problem/A
 * MemoryL: 256 MB
 * TimeL:   4000 ms
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
    int n; cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return ;
    }
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    int c = 1, v = 2;
    bool ok = false;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!ok) {
                g[i][j] = c;
                c += 2;
                if (c > n * n) ok = true;
            } else {
                g[i][j] = v;
                v += 2;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}