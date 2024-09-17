/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-13 11:14:03
 *
 * Problem: B. Min Cost String
 * Contest: Codeforces - SMU Autumn 2024 Trial 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/549671/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

// abcd
void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; i ++) cout << 'a';
        return ;
    }
    if (k == 2) {
        string s = "aabb";
        for (int i = 1; i <= n / 4; i ++) cout << s;
        for (int i = 1; i <= n % 4; i ++) cout << s[i - 1];
        return ;
    }
    map<char, char> mp;
    string s = "a";
    char f = 'a';
    for (int i = 2; i <= n; i ++) {
        if (!mp.count(s.back())) {
            mp[s.back()] = 'a';
            s += 'a';
        } else {
            char op = mp[s.back()] + 1;
            mp[s.back()] = op;
            s += op;
            if (op - 'a' + 1 == k && s.back() != f + 1) {
                f ++;
                mp[s.back()] = f;
                s += f;
            }
        }
        char tp = 'a' + k - 1;
        if (mp.count(s.back()) && mp[s.back()] == tp) break;
    }
    int m = (int)s.size();
    for (int i = 1; i <= n / m; i ++) cout << s;
    for (int i = 1; i <= n % m; i ++) cout << s[i - 1];
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

// aabbaabbaabbaabbaabbaabbaabbaabb
// aabaaabaaabaaabaaabaaabaaabaaaba