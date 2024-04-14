/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-14 19:16:04
 *
 * Problem: 小红的排列构造
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/80259/C
 * MemoryL: 524288 MB
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    for (auto [x, y] : mp) {
        if (y > 2) {
            cout << -1 << '\n';
            return ;
        }
    }
    set<int> sp, sq;
    for (int i = 1; i <= n; i ++) {
        sp.insert(i);
        sq.insert(i);
    }
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i ++) {
        if (sp.count(a[i])) {
            p[i] = a[i];
            sp.erase(a[i]);
        } else {
            q[i] = a[i];
            sq.erase(a[i]);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (p[i] == 0) {
            p[i] = *sp.begin();
            sp.erase(*sp.begin());
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (q[i] == 0) {
            q[i] = *sq.begin();
            sq.erase(*sq.begin());
        }
    }
    for (int i = 1; i <= n; i ++) cout << p[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++) cout << q[i] << " \n"[i == n];
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