/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-26 18:22:55 ms
 *
 * Problem: 数字游戏
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/1084/
 * MemoryL: 64 MB
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

vector<int> num;
int dp[]

int dfs(int pos, int pre, bool ok) {
    if (!pos) return 1;
    if (!ok && dp[pos][pre] != -1) return dp[]
}

int solve(int x) {
    num.clear();
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    dfs((int)num.size(), 0, 1);
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1, l, r;
    // cin >> h_h;
    while (cin >> l >> r) {
        cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}