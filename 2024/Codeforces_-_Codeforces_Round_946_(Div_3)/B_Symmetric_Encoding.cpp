/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:33
 *
 * Problem: B. Symmetric Encoding
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
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
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    for (auto i : s) st.insert(i);
    string str;
    map<char, char> pp;
    for (auto i : st) str += i;
    // debug1(str);
    for (int i = 0, j = str.size() - 1; i <= j; i ++, j --) {
        // debug2(str[i], str[j]);
        pp[str[i]] = str[j];
        pp[str[j]] = str[i];
    }
    // for (auto [x, y] : pp) cout << x << ' ' << y << '\n';
    for (auto &i : s) {
        i = pp[i];
    }
    cout << s << '\n';
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