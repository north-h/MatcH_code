/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-09 13:56:38 ms
 *
 * Problem: 天才的记忆
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/1275/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
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

template <class T>
struct Seg {
    struct Node { int l, r; T add, mx; };
    vector<Node> tr; vector<T> a; int n;
    void init(int N) {
        n = N;
        tr.resize(n * 4);
        a.resize(n);
    }
    void add(int x, T k) {
        a[x] = k;
    }
    void pushup(int u) {
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }
    void pushdown(int u) {
        if (tr[u].add) {
            tr[u << 1].mx = max(tr[u << 1].mx, tr[u].add);
            tr[u << 1].add = max(tr[u].add, tr[u << 1].add);
            tr[u << 1 | 1].mx = max(tr[u << 1 | 1].mx, tr[u].add);
            tr[u << 1 | 1].add = max(tr[u].add, tr[u << 1 | 1].add);
            tr[u].add = 0;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, a[l]};
        if (l == r) return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].add = k;
            tr[u].mx = max(tr[u].mx, k);
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    T query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
        pushdown(u);
        T mx = -INF;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) mx = max(mx, query(u << 1, l, r));
        if (r > mid) mx = max(mx, query(u << 1 | 1, l, r));
        return mx;
    }
};

void solve() {
    int n; cin >> n;
    Seg<int> sg;
    sg.init(n + 1);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        sg.add(i, x);
    }
    sg.build(1, 1, n);

    int m; cin >> m;
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        cout << sg.query(1, l, r) << '\n';
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