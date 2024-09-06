/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-06 21:53:12
 *
 * Problem: C2. Message Transmission Error (hard version)
 * Contest: Codeforces - Testing Round 19 (Div. 3)
 * URL:     https://codeforces.com/contest/2010/problem/C2
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

struct string_hash {
    const int base1 = 131, base2 = 13331;
    const int mod1 = 1e9 + 9, mod2 = 1e9 + 7;
    int n;
    vector<long long> h1, p1, h2, p2;
    string_hash() {};
    string_hash(const string &s) {
        n = s.size() - 1;
        h1.resize(n + 1), p1.resize(n + 1);
        h2.resize(n + 1), p2.resize(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= n; i ++) {
            p1[i] = p1[i - 1] * base1 % mod1;
            p2[i] = p2[i - 1] * base2 % mod2;
        }
        for (int i = 1; i <= n; i ++) {
            h1[i] = (h1[i - 1] * base1 % mod1 + s[i]) % mod1;
            h2[i] = (h2[i - 1] * base2 % mod2 + s[i]) % mod2;
        }
    }
    pair<int, int> get_hash(int l, int r) {
        int res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        int res2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
        return {res1, res2};
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size(), p = -1;
    s = " " + s;
    string_hash H(s);
    for (int i = n / 2 + 1; i < s.size() - 1; i ++) {
        if (H.get_hash(1, i) == H.get_hash(n - i + 1, n)) {
            p = i;
            break;
        }
    }
    if (p == -1) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        cout << s.substr(1, p) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}