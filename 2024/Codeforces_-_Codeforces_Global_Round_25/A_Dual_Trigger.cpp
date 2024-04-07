/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-07 00:19:41
 *
 * Problem: A. Dual Trigger
 * Contest: Codeforces - Codeforces Global Round 25
 * URL:     https://codeforces.com/contest/1951/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    for (auto i : s) c += (i == '1');
    if (c & 1 || (c == 2 && s.find("11") != -1)) cout << "NO" << endl;
    else cout << "YES" << endl;
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