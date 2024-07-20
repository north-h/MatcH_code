/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-20 20:21:56 ms
 *
 * Problem: C - Avoid K Palindrome 2
 * Contest: AtCoder - AtCoder Beginner Contest 363
 * URL:     https://atcoder.jp/contests/abc363/tasks/abc363_c
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    map<string, int> mp;
    int ans = 0;
    do {
        // if (mp.count(s)) continue;
        // mp[s] ++;
        bool ok = false;
        for (int i = 0; i + k - 1 < n; i++) {
            string s1 = s.substr(i, k);
            string s2 = s1;
            reverse(s1.begin(), s1.end());
            if (s1 == s2) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            // debug1(s);
            ans ++;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}