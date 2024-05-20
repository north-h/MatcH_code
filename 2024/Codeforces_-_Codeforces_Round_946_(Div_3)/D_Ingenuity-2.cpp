/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:41
 *
 * Problem: D. Ingenuity-2
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/D
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
#define PII pair<int, int>
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int vn = 0, vs = 0, ve = 0, vw = 0;
    for (auto i : s) {
        if (i == 'N') vn ++;
        else if (i == 'S') vs ++;
        else if (i == 'W') vw ++;
        else ve ++;
    }
    int sn = abs(vs - vn);
    int we = abs(vw - ve);
    if (sn & 1 || we & 1) {
        cout << "NO" << '\n';
        return ;
    }
    int m1 = min(vs, vn);
    int m2 = min(ve, vw);
    char f1 = 'N', f2 = 'W';
    if (vs > vn) f1 = 'S';
    if (ve > vw) f2 = 'E';
    string sans = s;
    for (auto &i : sans) i = '#';
    int ok1 = 0, ok2 = 0, ok = 0;
    for (int i = 0, j = 1, k = 1, l = 1, m = 1; i < s.size(); i ++) {
        if (s[i] == 'N' && j <= (m1 + 1) / 2) sans[i] = 'R', j ++, ok ++;
        else if (s[i] == 'S' && k <= (m1 + 1) / 2) sans[i] = 'R', k ++, ok ++;
        else if (s[i] == 'N' && l <= m1 / 2) sans[i] = 'H', l ++, ok ++;
        else if (s[i] == 'S' && m <= m1 / 2) sans[i] = 'H', m ++, ok ++;
    }
    if (m1 & 1) {
        for (int i = 0, j = 1, k = 1, l = 1, m = 1; i < s.size(); i ++) {
            if (s[i] == 'W' && j <= (m2 + 1) / 2) sans[i] = 'H', j ++, ok ++;
            else if (s[i] == 'E' && k <= (m2 + 1) / 2) sans[i] = 'H', k ++, ok ++;
            else if (s[i] == 'W' && l <= m2 / 2) sans[i] = 'R', l ++, ok ++;
            else if (s[i] == 'E' && m <= m2 / 2) sans[i] = 'R', m ++, ok ++;
        }
    } else {
        for (int i = 0, j = 1, k = 1, l = 1, m = 1; i < s.size(); i ++) {
            if (s[i] == 'W' && j <= (m2 + 1) / 2) sans[i] = 'R', j ++, ok ++;
            else if (s[i] == 'E' && k <= (m2 + 1) / 2) sans[i] = 'R', k ++, ok ++;
            else if (s[i] == 'W' && l <= m2 / 2) sans[i] = 'H', l ++, ok ++;
            else if (s[i] == 'E' && m <= m2 / 2) sans[i] = 'H', m ++, ok ++;
        }
    }
    for (int i = 0, j = 1; i < s.size() && j; i ++) {
        if (s[i] == f1 && sans[i] == '#' && j <= sn) {
            if (j & 1) sans[i] = 'R', ok1 ++;
            else sans[i] = 'H', ok2 ++;
            j ++;
        }
    }
    for (int i = 0, j = 1; i < s.size(); i ++) {
        if (s[i] == f2 && sans[i] == '#' && j <= we) {
            if (j & 1) sans[i] = 'R', ok1 ++;
            else sans[i] = 'H', ok2 ++;
            j ++;
        }
    }
    if (!ok1 && !ok2 && ok <= 2) sans = "NO";
    cout << sans << '\n';
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