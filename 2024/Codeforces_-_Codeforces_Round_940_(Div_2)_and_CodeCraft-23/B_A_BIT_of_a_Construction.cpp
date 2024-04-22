/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-21 22:41:09
 *
 * Problem: B. A BIT of a Construction
 * Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
 * URL:     https://codeforces.com/contest/1957/problem/B
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
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return ;
    }
    if (n == 2) {
        int cnt = 0;
        int y = k;
        while (y) cnt ++, y /= 2;
        int x = (1 << cnt - 1) - 1;
        if (y == 1) cout << x << ' ' << k - x << '\n';
        else cout << k << ' ' << 0 << '\n';
        return ;
    }
    vector<int> ans;
    int sum = 0;
    for (int i = 1, j = 1; sum + i <= k && j <= n; i *= 2, j ++) {
        ans.push_back(i);
        sum += i;
    }
    while (ans.size() < n) ans.push_back(0);
    int remain = k - sum;
    sort(ans.rbegin(), ans.rend());
    int m = (int)ans.size();
    for (int i = m; i >= 0; i --) {
        if ((1 << i) * 2 <= remain) {
            remain -= (1 << i) * 2;
            int f = 2;
            for (int j = 0; j < ans.size(); j ++) {
                if (ans[j] >> i & 1) continue;
                ans[j] += (1 << i);
                f --;
                if (!f) break;
            }
        }
    }
    if (remain == 1) {
        for (auto & i : ans) {
            if (i % 2 == 0) {
                i ++;
                break;
            }
        }
    }
    int s = 0, ss = 0;
    for (auto i : ans) {
        cout << i << ' ';
        // s ^= i; ss += i;
    }
    cout << '\n';
    // debug2(s, ss);
    // vector<int> b;
    // while (s) {
    //     b.push_back(s % 2);
    //     s /= 2;
    // }
    // reverse(b.begin(), b.end());
    // for (auto i : b) cout << i << ' ';
    // cout << '\n';
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