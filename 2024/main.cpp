/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-26 18:29:09
 *
 * Problem: M. Merge
 * Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
 * URL:     https://codeforces.com/gym/105143/problem/M
 * MemoryL: 1024 MB
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

int n, k;

void solve() {
    cin >> n >> k;
    if (n < k || k == 1) {cout << n << '\n';return ;}
    if (n == k) {cout << 1 << '\n';return ;}
    int ans = 0;
    while (n) {
        int sum = 1;
        while (sum * k <= n) sum *= k;
        ans += n / sum;
        n -= n / sum * sum;
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