/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-11 21:04:53
 *
 * Problem: D. Journey to Un'Goro
 * Contest: Codeforces - SMU 2024 ICPC 网络赛选拔赛2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548717/problem/D
 * MemoryL: 1024 MB
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

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) ans += (n - i + 1);
    int lt = (n + 2) / 2;
    // debug2(lt0, lt1);
    string s;
    bool ok = false;
    int res = 0;
    auto dfs = [&](auto dfs, int v1, int v0, int p, int f) -> void {
        if (ok) return ;
        if (v1 > lt || v0 > lt) {
            return ;
        }
        if (p == n) {
            cout << s << '\n';
            res ++;
            if (res == 100) ok = true;
            return ;
        }
        s .append("b");
        dfs(dfs, v1 + f, v0 + !f, p + 1, f);
        s.pop_back();
        f ^= 1;
        s .append("r");
        dfs(dfs, v1 + f, v0 + !f, p + 1, f);
        s.pop_back();
    };
    cout << ans << '\n';
    dfs(dfs, 0, 1, 0, 0);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}