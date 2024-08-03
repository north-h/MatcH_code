/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-03 20:00:23 ms
 *
 * Problem: C - Transportation Expenses
 * Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
 * URL:     https://atcoder.jp/contests/abc365/tasks/abc365_c
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= m) {
        cout << "infinite" << '\n';
        return ;
    }
    auto check = [&](int x) -> bool {
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            res += min(a[i], x);
        }
        return res <= m;
    };
    int l = 0, r = sum, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}