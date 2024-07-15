/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-13 20:02:52 ms
 *
 * Problem: C - Sum = 0
 * Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
 * URL:     https://atcoder.jp/contests/abc362/tasks/abc362_c
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> L[i] >> R[i];
        l += L[i];
        r += R[i];
    }
    if (l > 0 || r < 0) cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        int sum = abs(l);
        for (int i = 1; i <= n; i ++) {
            int x = R[i] - L[i];
            if (sum - x >= 0) {
                sum -= x;
                cout << R[i] << ' ';
            } else {
                cout << L[i] + sum << ' ';
                sum = 0;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}