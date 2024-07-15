/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-16 01:07:30
 *
 * Problem: P4513 小白逛公园
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P4513
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 500010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct Info {
    int l = 1, r = 1, lazy;
    int mx, lmx, rmx, sum;
    int mn, lmn, rmn;
} tr[N * 4];

int a[N];

Info operator + (const Info &ls, const Info &rs) {
    Info u;
    u.l = ls.l; u.r = rs.r;
    u.sum = ls.sum + rs.sum;

    u.lmx = max(ls.lmx, ls.sum + rs.lmx);
    u.rmx = max(rs.rmx, rs.sum + ls.rmx);
    u.mx = max(max(ls.mx, rs.mx), ls.rmx + rs.lmx);

    u.lmn = min(ls.lmn, ls.sum + rs.lmn);
    u.rmn = min(rs.rmn, rs.sum + ls.rmn);
    u.mn = min(min(ls.mn, rs.mn), ls.rmn + rs.lmn);
    return u;
}

void apply(Info &u, int lazy) {
    u.lazy = u.mx = u.lmx = u.rmx = u.sum = lazy;
}

// template<class Info, class T>
// struct SegmentTree {
//     int n;
//     vector<Info> tr;
//     vector<T> a;
//     SegmentTree(const vector<T> &init) {
//         n = init.size();
//         tr.assign(n * 4 + 1, Info());
// //        a.assign(n + 1, T());
//         a = init;
//         build(1, 1, n);
//     }
void pushup(int u) {
    tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
void pushdown(int u) {
    apply(tr[u << 1], tr[u].lazy);
    apply(tr[u << 1 | 1], tr[u].lazy);
    tr[u].lazy = 0;
}
void build(int u, int l, int r) {
    tr[u] = {l, r, 0, a[l], a[l], a[l], a[l], a[l], a[l], a[l]};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void modify(int u, int l, int r, int k) {
    if (tr[u].l >= l && tr[u].r <= r) {
        ::apply(tr[u], k);
        return;
    }
    // pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) modify(u << 1, l, r, k);
    if (r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}
Info query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    // pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    Info t = query(u << 1, l, r) + query(u << 1 | 1, l, r);
    return t;
}
// };

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1, x; i <= n; i ++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m --) {
        int op; cin >> op;
        // debug1(op);
        if (op == 1) {
            int l, r; cin >> l >> r;
            if (l > r) swap(l, r);
            cout << query(1, l, r).mx << '\n';
        } else {
            int x, k; cin >> x >> k;
            modify(1, x, x, k);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}