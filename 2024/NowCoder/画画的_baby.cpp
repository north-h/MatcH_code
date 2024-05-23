/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-23 13:08:46 ms
 *
 * Problem: 画画的 baby
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/83318/F
 * MemoryL: 1048576 MB
 * TimeL:   4000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 1000100;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int N) {
        n = N + 1;
        sum1.resize(n);
        sum2.resize(n);
    }
    void add(int x, T k) {
        for (int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for (int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> a(n + 1);
    map<int, int> mp;
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
        mx = max(a[i][1], mx);
    }
    vector<int> hang(N), lie(N);
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    for (int i = 1; i <= n; i ++) {
        mp[a[i][0]] += a[i][1];
    }
    int ans = 0;
    BIT<int> bit(mx + 1);
    for (auto [x, y] : mp) {
        debug2(x, y);
        debug2(hang[x], lie[y]);
        if (!hang[x]) ans += y;
        else ans += y - hang[x];
        hang[x] = y;
        if (!lie[y]) ans += x;
        else ans += x - lie[y];
        lie[y] = x;
        ans --;
        debug1(ans);
        ans -= bit.range_query(y + 1, mx);
        bit.range_add(y, y, 1);
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