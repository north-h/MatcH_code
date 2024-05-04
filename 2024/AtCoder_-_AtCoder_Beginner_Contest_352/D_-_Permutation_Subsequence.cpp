/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-04 20:14:51 ms
 *
 * Problem: D - Permutation Subsequence
 * Contest: AtCoder - AtCoder Beginner Contest 352
 * URL:     https://atcoder.jp/contests/abc352/tasks/abc352_d
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
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

template<class T>
struct RMQ {
    T n; vector<vector<T>> f, g;
    vector<int> lg2;
    RMQ(const vector<T> &a) {
        n = a.size();
        lg2.resize(n + 1);
        lg2[0] = -1;
        for (int i = 1; i <= n; i ++) {
            lg2[i] = lg2[i >> 1] + 1;
        }
        f.resize(n + 1, vector<T>(lg2[n] + 1));
        g.resize(n + 1, vector<T>(lg2[n] + 1));
        for (int i = 1; i <= n; i++) {
            f[i][0] = a[i];
            g[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query_max(int l, int r) {
        int k = lg2[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }

    T query_min(int l, int r) {
        int k = lg2[r - l + 1];
        return min(g[l][k], g[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<array<int, 2>> p(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> p[i][0];
        p[i][1] = i;
    }
    sort(p.begin() + 1, p.end());
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        a[i] = p[i][1];
    }
    RMQ<int> rmq(a);
    int ans = INF;
    for (int i = k; i <= n; i ++) {
        int mx = rmq.query_max(i - k + 1, i);
        int mn = rmq.query_min(i - k + 1, i);
        ans = min(ans, mx - mn);
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