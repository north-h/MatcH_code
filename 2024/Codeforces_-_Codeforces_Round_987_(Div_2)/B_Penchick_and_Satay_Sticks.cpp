/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-15 20:48:53
 *
 * Problem: B. Penchick and Satay Sticks
 * Contest: Codeforces - Codeforces Round 987 (Div. 2)
 * URL:     https://codeforces.com/contest/2031/problem/B
 * MemoryL: 256 MB
 * TimeL:   1500 ms
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
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i ++) cin >> p[i];
    vector<int> suf(n + 1, 0);
    suf[n] = p[n];
    for (int i = n - 1; i >= 1; i --) {
        suf[i] = min(p[i], suf[i + 1]);
    }
    bool ok = true;
    for (int i = 1; i <= n; i ++) {
        if (suf[i] < p[i] - 1) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}