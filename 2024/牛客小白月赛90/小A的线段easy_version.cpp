/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 19:59:49 ms
 *
 * Problem: 小A的线段（easy version）
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/D
 * MemoryL: 524288 MB
 * TimeL:   4000 ms
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
const int mod = 998244353;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    int ans = 0;
    vector<array<int, 2>> seg(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> seg[i][0] >> seg[i][1];
    }
    vector<array<int, 2>> an;
    auto dfs = [&](auto && dfs, int p)-> void {
        if (p > m) {
            vector<int> s(n + 10);
            for (auto [l, r] : an) {
                s[l] ++; s[r + 1] --;
            }
            for (int i = 1; i <= n; i ++) s[i] += s[i - 1];
            int c = 0;
            for (int i = 1; i <= n; i ++) {
                if (s[i] >= 2) c ++;
            }
            if (c == n) ans ++;
            return ;
        }
        an.push_back(seg[p]);
        dfs(dfs, p + 1);
        an.pop_back();

        dfs(dfs, p + 1);

    };
    dfs(dfs, 1);
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