/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 20:25:18 ms
 *
 * Problem: 小A的任务
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/E
 * MemoryL: 524288 MB
 * TimeL:   6000 ms
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
using i2 = array<int, 2>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    vector<ll> sa(n + 1), sb(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    while (q --) {
        int k;
        cin >> k;
        ll ans = 1e18;
        priority_queue<int> pq;
        multiset<int> st;
        for (int i = 1; i <= n; i ++) {
            pq.push(b[i]);
            st.insert(b[i]);
            while ((int)pq.size() > k) {
                st.erase(pq.top());
                pq.pop();
            }
            if ((int)pq.size() == k) ans = min(ans, *st.rbegin() + sa[i]);
        }
        cout << ans << endl;
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