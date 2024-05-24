/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-11 20:00:30 ms
 *
 * Problem: E - Yet Another Sigma Problem
 * Contest: AtCoder - AtCoder Beginner Contest 353
 * URL:     https://atcoder.jp/contests/abc353/tasks/abc353_e
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
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

int tr[N][26], cnt[N];
int n, idx;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        string s; cin >> s;
        int p = 1;
        for (int j = 0; j  < s.size(); j ++) {
            cnt[p] ++;
            int u = s[j] - 'a';
            if (!tr[p][u]) tr[p][u] = ++ idx;
            p = tr[u][p];
        }
    }
    // debug1(idx);
    ll ans = 0;
    for (int i = 1; i <= idx; i ++) {
        cout << cnt[i] << ' ';
        ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << '\n';
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