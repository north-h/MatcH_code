#include<bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
#define ls tr[u].son[0]
#define rs tr[u].son[1]
    struct Info {
        int son[2];
        int ok = -1;
        T sum = 0;
    };
    int n, idx = 0, root = 0;
    vector<Info> tr;
    SegmentTree(int n) {
        tr.resize(n + 1);
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
    void calc(Info &u, int ok, int l, int r) {
        int lvl = r - l + 1;
        if (ok == 0) u.sum = lvl;
        else u.sum = 0;
        u.ok = ok;
    }
    void pushdown(int &u, int l, int r) {
        int ok = tr[u].ok;
        if (ok == -1) return ;
        build(ls); build(rs);
        int mid = l + r >> 1;
        calc(tr[ls], ok, l, mid);
        calc(tr[rs], ok, mid + 1, r);
        tr[u].ok = -1;
    }
    void modify(int &u, int l, int r, int L, int R, int ok) {
        build(u);
        if (l >= L && r <= R) {
            calc(tr[u], ok, l, r);
            return ;
        }
        pushdown(u, l, r);
        int mid = l + r >> 1;
        if (L <= mid) modify(ls, l, mid, L, R, ok);
        if (R > mid) modify(rs, mid + 1, r, L, R, ok);
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
    int query(int &u, int l, int r, int k) {
        build(u);
        if (l == r) return l;
        pushdown(u, l, r);
        int cnt = tr[ls].sum;
        int mid = l + r >> 1;
        if (cnt >= k) return query(ls, l, mid, k);
        else return query(rs, mid + 1, r, k - cnt);
    }
};