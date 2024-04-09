/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-09 13:04:39 ms
 *
 * Problem: P8703 [蓝桥杯 2019 国 B] 最优包含
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8703?contestId=166591
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * =========================================================
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
    string a, b;
    cin >> a >> b;
    int ans = INF;
    string s;
    vector<int> T;
    auto dfs = [&](auto && dfs, int p) -> void {
        if (p == b.size()) {
            vector<int> t;
            for (int i = 0, j = 0; i < a.size() && j < s.size(); i ++) {
                if (a[i] == s[j]) {
                    j ++; t.push_back(i);
                }
            }
            bool ok = true;
            if (t.size() == 0 || T.size() == 0) return ;
            if (t[0] != T[0] && t[0] == 0) ok = false;
            if (t.back() != T.back() && t[0] == t.size() - 1) ok= false;
            if (ok) ans = min(ans, (int)(b.size() - s.size()));
            return ;
        }

        s += b[p];
        T.push_back(p);
        dfs(dfs, p + 1);
        s.pop_back();
        T.pop_back();

        dfs(dfs, p + 1);
    };
    dfs(dfs, 0);
    cout << ans << endl;
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