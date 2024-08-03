/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-01 01:15:21
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
#define ls tr[u].l
#define rs tr[u].r
    struct Info {
        int l, r;
        T sum, add;
    };
    int n, idx = 0, root = 0;
    vector<Info> tr;
    SegmentTree(int n) {
        tr.resize(n * log2(N));
    };
    Info merge(Info &u, Info l, Info r) {
        u.sum = l.sum + r.sum;
        return u;
    }
    void build(int &u) {
        if (u) return ;
        u = ++ idx;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[ls], tr[rs]);
    }
    void calc(Info &u, T add, int l, int r) {
        int lvl = r - l + 1;
        u.sum += lvl * add;
        u.add += add;
    }
    void pushdown(int u, int l, int r) {
        int add = tr[u].add;
        if (!add) return ;
        build(ls);
        build(rs);
        int mid = l + r >> 1;
        calc(tr[ls], add, l, mid);
        calc(tr[rs], add, mid + 1, r);
        tr[u].add = 0;
    }
    void modify(int &u, int l, int r, int L, int R, T add) {
        build(u);
        if (l >= L && r <= R) {
            calc(tr[u], add, l, r);
            return ;
        }
        pushdown(u, l, r);
        int mid = l + r >> 1;
        if (L <= mid) modify(ls, l, mid, L, R, add);
        if (R > mid) modify(rs, mid + 1, r, L, R, add);
        pushup(u);
    }
    Info query(int &u, int l, int r, int L, int R) {
        build(u);
        if (l >= L && r <= R) return tr[u];
        pushdown(u, l, r);
        int mid = l + r >> 1;
        if (R <= mid) return query(ls, l, mid, L, R);
        if (L > mid) return query(rs, mid + 1, r, L, R);
        Info t = merge(t, query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
        return t;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    SegmentTree<int> sg(n);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        sg.modify(sg.root, 1, n, i, i, x);
    }
    while (m --) {
        int op, l, r, k; cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            sg.modify(sg.root, 1, n, l, r, k);
        } else cout << sg.query(sg.root, 1, n, l, r).sum << '\n';
    }
    // cout << sg.idx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}