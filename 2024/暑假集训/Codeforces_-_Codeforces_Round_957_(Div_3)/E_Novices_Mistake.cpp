/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-12 09:19:31 ms
 *
 * Problem: E. Novice's Mistake
 * Contest: Codeforces - Codeforces Round 957 (Div. 3)
 * URL:     https://codeforces.com/contest/1992/problem/E
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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
    int n; cin >> n;
    vector<array<int, 2>> ans;
    string sn = to_string(n);
    for (int a = 1; a <= 10000; a ++) {
        int sz = to_string(a * n).size();
        string st = "";
        for (int i = 0; i < sz && st.size() <= sz; i ++) {
            for (int j = 0; j < sn.size() && st.size() <= sz; j ++) {
                st += sn[j];
                int b = a * n - stoll(st);
                if (b <= 0 || b > 10000 || sn.size() * a - b != st.size()) continue;
                ans.push_back({a, b});
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}