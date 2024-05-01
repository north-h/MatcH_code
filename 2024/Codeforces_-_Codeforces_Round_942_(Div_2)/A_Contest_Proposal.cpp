/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-30 22:48:17
 *
 * Problem: A. Contest Proposal
 * Contest: Codeforces - Codeforces Round 942 (Div. 2)
 * URL:     https://codeforces.com/contest/1972/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    // sort(a.begin() + 1, a.end());
    // sort(b.begin() + 1, b.end());
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int c = INF, p = -1;
        for (int j = 1; j <= n; j ++) {
            if (b[j] - a[i] >= 0 && b[j] - a[i] < c && !vis[j]) {
                c = b[j] - a[i];
                p = j;
            }
        }
        if (p == -1) ans ++;
        else vis[p] = 1;
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
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}