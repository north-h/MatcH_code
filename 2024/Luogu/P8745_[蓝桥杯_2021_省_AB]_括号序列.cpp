/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 12:00:56 ms
 *
 * Problem: P8745 [蓝桥杯 2021 省 AB] 括号序列
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8745?contestId=165868
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int f1 = 0, f2 = 0;
    for (auto i : s) {
        if (i == '(') f1 ++;
        if (i == ')') f2 ++;
    }
    int ans = 0;
    string sans;
    auto check = [&](string s) -> bool {
        stack<char> stk;
        for (auto i : s) {
            // debug1(i);
            if (i == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) return false;
                else {
                    if (stk.top() != '(') return false;
                    stk.pop();
                }
            }
        }
        if (stk.size()) return false;
        return true;
    };
    auto dfs = [&](auto &&self, int p, int c) -> void {
        if (p > (int)s.size() + 1 && c == 0) {
            if (check(sans)) ans ++;
            return ;
        }
        if (c == 0) {
            sans += s.substr(p);
            if (check(sans)) ans ++;
            return ;            
        } else {
            if (p == s.size() + 1) {
                sans += ')';
                self(self, p + 1, c - 1);
                sans.pop_back();

                self(self, p + 1, c);
            } else {
                sans += s[p];
                sans += ')';
                self(self, p + 1, c - 1);
                sans.pop_back();
                sans.pop_back();

                sans += s[p];
                self(self, p + 1, c - 1);
                sans.pop_back();
            }
        }
    };
    dfs(dfs, 0, f1 - f2);
    cout << ans << endl;;
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