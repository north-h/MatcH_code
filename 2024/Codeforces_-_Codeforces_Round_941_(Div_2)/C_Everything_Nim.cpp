/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-28 08:49:02
 *
 * Problem: C. Everything Nim
 * Contest: Codeforces - Codeforces Round 941 (Div. 2)
 * URL:     https://codeforces.com/contest/1966/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    // for (auto i : a) cout << i << ' '; cout << '\n';
    int c = 0;
    for (int i = 1; i < a.size(); i ++) c += (a[i] - a[i - 1]);
    int f = 0;
    for (int i = 0, v = 0; i < a.size(); i ++) {
        if (a[i] - a[i - 1] == 1) {
            if (c & 1) f ^= 1;
            c --;
        }
    }
    if (f == 0) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}