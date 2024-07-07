/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-06 13:14:19 ms
 *
 * Problem: D. Mathematical Problem
 * Contest: Codeforces - Codeforces Round 954 (Div. 3)
 * URL:     https://codeforces.com/contest/1986/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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

void solve() {
    int n; string s;
    cin >> n >> s;
    int ans = INF;
    if (s.size() <= 2) {
        reverse(s.begin(), s.end());
        while (s.size() > 1 && s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        cout << s << '\n';
        return ;
    }
    for (int i = 0; i < s.size() - 1; i ++) {
        vector<int> num;
        for (int k = 0; k < s.size(); k ++) {
            if (k == i) num.push_back((s[k] - '0') * 10 + s[k + 1] - '0'), k ++;
            else num.push_back(s[k] - '0');
        }
        int cv = num[0];
        for (int i = 1; i < num.size(); i ++) {
            cv = min(cv * num[i], cv + num[i]);
        }
        ans = min(cv, ans);
    }
    cout << ans << '\n';
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