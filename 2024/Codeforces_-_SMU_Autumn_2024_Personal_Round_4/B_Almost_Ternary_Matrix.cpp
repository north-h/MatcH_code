/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 12:11:21
 *
 * Problem: B. Almost Ternary Matrix
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/B
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> s = {1, 0, 0, 1}, ss = {0, 1, 1, 0};
    for (int i = 1; i <= n / 2; i ++) {
        if (i & 1) {
            for (int j = 1; j <= m / 4; j ++) {
                for (auto k : s) cout << k << ' ';
            }
            if (m % 4 == 2) cout << "1 0";
            cout << '\n';
            for (int j = 1; j <= m / 4; j ++) {
                for (auto k : ss) cout << k << ' ';
            }
            if (m % 4 == 2) cout << "0 1";
            cout << '\n';
        } else {
            for (int j = 1; j <= m / 4; j ++) {
                for (auto k : ss) cout << k << ' ';
            }
            if (m % 4 == 2) cout << "0 1";
            cout << '\n';
            for (int j = 1; j <= m / 4; j ++) {
                for (auto k : s) cout << k << ' ';
            }
            if (m % 4 == 2) cout << "1 0";
            cout << '\n';
        }
    }
    // cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}