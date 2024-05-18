/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-17 17:59:09 ms
 *
 * Problem: P3375 【模板】KMP
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3375
 * MemoryL: 512 MB
 * TimeL:   1000 ms
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
    string s, p;
    cin >> s >> p;
    s = " " + s;
    p = " " + p;
    vector<int> nxt((int)p.size() + 1);
    for (int i = 2, j = 0; i < p.size(); i ++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j ++;
        nxt[i] = j;
    }
    for (int i = 1, j = 0; i < s.size(); i ++) {
        while (j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == p.size() - 1) {
            cout << i - (p.size() - 1) + 1 << '\n';
            j = nxt[j];
        }
    }
    for (int i = 1; i < p.size(); i ++) cout << nxt[i] << ' '; cout << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}