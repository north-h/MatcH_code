/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:41 ms
 *
 * Problem: P8736 [蓝桥杯 2020 国 B] 游园安排
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8736?contestId=173756
 * MemoryL: 128 MB
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
    string s; cin >> s;
    string T;
    vector<string> a;
    T += s[0];
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            a.push_back(T);
            T.clear();
        }
        T += s[i];
    }
    a.push_back(T);
    sort(a.begin(), a.end());
    string sans = "";
    for (auto i : a) {
        if (sans.size() > i.size()) break;
        cout << i;
        sans = i;
    }
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