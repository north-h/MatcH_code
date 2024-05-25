/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 20:00:26 ms
 *
 * Problem: D - Intersecting Intervals
 * Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
 * URL:     https://atcoder.jp/contests/abc355/tasks/abc355_d
 * MemoryL: 1024 MB
 * TimeL:   3000 ms
 * ==============================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 500010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int N) {
        n = N;
        sum1.resize(n + 1);
        sum2.resize(n + 1);
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
    vector<array<int, 2>> edge(n + 1);
    vector<int> t;
    for (int i = 1; i <= n; i ++) {
        cin >> edge[i][0] >> edge[i][1];
        t.push_back(edge[i][0]);
        t.push_back(edge[i][1]);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < t.size(); i ++) {
        mp[t[i]] = i + 1;
    }
    sort(edge.begin() + 1, edge.end());
    ll ans = (ll)n * (n - 1) / 2;
    BIT<int> bit(t.size() * 2 + 1);
    for (int i = 1; i <= n; i ++) {
        auto [l, r] = edge[i];
        ans -= bit.range_query(1, mp[l] - 1);
        bit.range_add(mp[r], mp[r], 1);
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