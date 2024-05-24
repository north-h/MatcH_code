/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-24 18:26:44 ms
 *
 * Problem: P2003 [CRCI 2008] PLATFORME 平板
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P2003
 * MemoryL: 125 MB
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
    struct Node { int l, r; T lazy, mx, mn, sum; };
    vector<Node> tr; vector<T> a; int n;
    Seg(int N) { n = N + 1; tr.resize(n * 4); a.resize(n);}
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    Node merge(Node t, Node l, Node r) {
        t.sum = l.sum + r.sum;
        return t;
    }
    void pushdown(int u) {
        if (tr[u].lazy) {
            tr[u << 1].lazy = tr[u].lazy;
            tr[u << 1].sum = (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].lazy;
            tr[u << 1 | 1].lazy = tr[u].lazy;
            tr[u << 1 | 1].sum = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].lazy;
            tr[u].lazy = 0;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, a[l], a[l], a[l]};
        if (l == r) return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy = k;
            tr[u].sum = (tr[u].r - tr[u].l + 1) * k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        return t;
    }
};

void solve() {
    int n; cin >> n;
    Seg<int> sg(N);
    sg.build(1, 1, N);
    vector<array<int, 3>> a(n);
    for (auto &[x, y, z] : a) cin >> x >> y >> z;
    sort(a.begin(), a.end());
    int ans = 0;
    for (auto [x, y, z] : a) {
        // debug2(y, z);
        ans += x - sg.query(1, y + 1, y + 1).sum;
        ans += x - sg.query(1, z, z).sum;
        // debug1(ans);
        sg.modify(1, y + 1, z, x);
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