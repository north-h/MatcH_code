/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:45 ms
 *
 * Problem: E. Knowledge is Power
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/E
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
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

void solve(int t) {
    int n; cin >> n;
    cout << "Case #" << t << ": ";
    if (n == 6) cout << -1 << '\n';
    else if (n & 1) {
        cout << 1 << '\n';
    } else if (n / 2 % 2 == 0) {
        cout << 2 << '\n';
    } else {
        if (n % 3 == 0) {
            int a = n / 3 - 1, b = n / 3, c = n / 3 + 1;
            if (__gcd(a, b) == 1 && __gcd(c, b) == 1 && __gcd(a, c) == 1) cout << 2 << '\n';
            else cout << 4 << '\n';
        }
        else if (n % 3 == 1) {
            int a = n / 3 - 1, b = n / 3, c = n / 3 + 2;
            if (__gcd(a, b) == 1 && __gcd(c, b) == 1 && __gcd(a, c) == 1) cout << 3 << '\n';
            else cout << 4 << '\n';
        } else {
            int a = n / 3 - 1, b = n / 3 + 1, c = n / 3 + 2;
            if (__gcd(a, b) == 1 && __gcd(c, b) == 1 && __gcd(a, c) == 1) cout << 3 << '\n';
            else cout << 4 << '\n';
        }
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1, t = 1;
    cin >> h_h;
    while (h_h--)solve(t ++);
    return 0;
}