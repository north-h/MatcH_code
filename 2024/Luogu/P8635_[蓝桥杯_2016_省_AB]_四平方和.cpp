/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 12:10:37 ms
 *
 * Problem: P8635 [蓝桥杯 2016 省 AB] 四平方和
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8635?contestId=173756
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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
    int n; cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i <= sqrt(n); i ++) {
        for (int j = 0; j <= sqrt(n); j ++) {
            mp[i * i + j * j] .push_back({i, j});
        }
    }
    for (auto [x, y] : mp) {
        // cout << x << '\n';
        sort(y.begin(), y.end());
    }
    for (int i = 0; i <= sqrt(n); i ++) {
        for (int j = 0; j <= sqrt(n); j ++) {
            int x = n - i * i - j * j;
            if (mp.count(x)) {
                vector<int> t = {i, j, mp[x][0].first, mp[x][0].second};
                sort(t.begin(), t.end());
                for (auto i : t) cout << i << ' ';
                return ;
            }
        }
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