/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-13 22:41:18
 *
 * Problem: C. Numeric String Template
 * Contest: Codeforces - Codeforces Round 966 (Div. 3)
 * URL:     https://codeforces.com/contest/2000/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int m; cin >> m;
    while (m --) {
        string s; cin >> s;
        map<char, int> mp1;
        map<int, char> mp2;
        if (s.size() != n) cout << "NO\n";
        else {
            s = " " + s;
            bool ok = true;
            for (int i = 1; i < s.size(); i ++) {
                if (!mp1.count(s[i]))  {
                    mp1[s[i]] = a[i];
                    if (!mp2.count(a[i])) mp2[a[i]] = s[i];
                    else {
                        if (mp2[a[i]] != s[i]) ok = false;
                    }
                } else if (!mp2.count(a[i])) {
                    mp2[a[i]] = s[i];
                    if (mp1[s[i]] != a[i]) ok = false;
                } else if (mp1[s[i]] != a[i] || mp2[a[i]] != s[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}