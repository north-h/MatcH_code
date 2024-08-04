/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-04 22:35:43
 *
 * Problem: A. Question Marks
 * Contest: Codeforces - Codeforces Round 963 (Div. 2)
 * URL:     https://codeforces.com/contest/1993/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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
    map<char, int> mp;
    string s; cin >> s;
    for (auto i : s) mp[i] ++;
    int ans = 0;
    if (mp['A']) ans += min(n, mp['A']);
    if (mp['B']) ans += min(n, mp['B']);
    if (mp['C']) ans += min(n, mp['C']);
    if (mp['D']) ans += min(n, mp['D']);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}