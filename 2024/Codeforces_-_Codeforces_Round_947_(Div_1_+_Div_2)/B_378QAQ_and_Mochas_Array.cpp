/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-25 22:43:09
 *
 * Problem: B. 378QAQ and Mocha's Array
 * Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
 * URL:     https://codeforces.com/contest/1975/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int a1 = a[1], a2 = -1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] % a1 != 0) {
            a2 = a[i];
            break;
        }
    }
    if (a2 == -1) {
        cout << "Yes" << '\n';
        return ;
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i] % a1 != 0 && a[i] % a2 != 0) {
            cout << "No" << '\n';
            return ;
        }
    }
    cout << "Yes" << '\n';
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