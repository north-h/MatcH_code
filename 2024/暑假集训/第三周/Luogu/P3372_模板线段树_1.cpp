/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-22 23:34:00
 *
 * Problem: P3372 【模板】线段树 1
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3372
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template<class T>
struct SegmentTree {
#define ls u << 1
#define rs u << 1 | 1
    struct Info {
        int l, r;
        T add;
        T sum;
    };
    vector<Info> tr;
    vector<T> a;
    SegmentTree(const vector<T> &init) {
        int n = init.size();
        tr.resize(n * 4);
        a = init;
        build(1, 1, n);
    }
    Info merge(Info u, Info l, Info r) {
        u.sum = l.sum + r.sum;
        return u;
    }
    void calc(Info &u, int add) {
        int lvl = u.r - u.l + 1;
        u.sum += lvl * add;
        u.add += add;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        auto [_, __, a, _1] = tr[u];
        calc(tr[ls], a);
        calc(tr[rs], a);
        tr[u].add = 0;
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, a[l]};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T add) {
        if (tr[u].l >= l && tr[u].r <= r) {
            calc(tr[u], add);
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(ls, l, r, add);
        if (r > mid) modify(rs, l, r, add);
        pushup(u);
    }
    Info query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(ls, l, r);
        if (l > mid) return query(rs, l, r);
        Info t = merge(t, query(ls, l, r), query(rs, l, r));
        pushup(u);
        return t;
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    SegmentTree<int> sg(a);
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, z; cin >> x >> y >> z;
            sg.modify(1, x, y, z);
        } else {
            int x, y; cin >> x >> y;
            cout << sg.query(1, x, y).sum << '\n';
        }
        // for (int i = 1; i <= n; i ++) {
        //     cout << sg.query(1, i, i).sum << ' ';
        // }
        // cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}