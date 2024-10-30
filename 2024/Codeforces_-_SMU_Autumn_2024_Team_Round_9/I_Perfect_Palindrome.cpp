/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-28 14:42:47
 *
 * Problem: I. Perfect Palindrome
 * Contest: Codeforces - SMU Autumn 2024 Team Round 9
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/561296/problem/I
 * MemoryL: 512 MB
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

void solve() {
    string s; cin >> s;
    map<int, int> mp;
    for (auto i : s) mp[i] ++;
    int ans = 0;
    for (auto [x, y] : mp) ans = max(ans, y);
    cout << s.size() - ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}