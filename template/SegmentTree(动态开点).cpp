#include<bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
#define ls tr[u].lid
#define rs tr[u].rid
    struct Info {
        int lid, rid, l, r;
        
    };
    int n, idx = 0, root = 0;
    vector<Info> tr;
    SegmentTree(int n) {
        tr.resize(n * 2 + 1);
    };
    Info merge(Info &u, Info l, Info r) {

        return u;
    }
    void build(int &u, int l, int r) {
        if (u) return ;
        u = ++ idx;
        tr[u].add = 0;
        tr[u].l = l, tr[u].r = r;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[ls], tr[rs]);
    }
    void calc(Info &u, T add) {
        int lvl = u.r - u.l + 1;

    }
    void pushdown(int u) {
        int add = tr[u].add;
        if (!add) return ;
        calc(tr[ls], add);
        calc(tr[rs], add);
        tr[u].add = 0;
    }
    void modify(int &u, int l, int r, int L, int R, T add) {
        build(u, l, r);
        if (l >= L && r <= R) {
            calc(tr[u], add);
            return ;
        }
        pushdown(u);
        int mid = l + r >> 1;
        if (L <= mid) modify(ls, l, mid, L, R, add);
        if (R > mid) modify(rs, mid + 1, r, L, R, add);
        pushup(u);
    }
    Info query(int &u, int l, int r, int L, int R) {
        build(u, l, r);
        if (l >= L && r <= R) return tr[u];
        pushdown(u);
        int mid = l + r >> 1;
        if (R <= mid) return query(ls, l, mid, L, R);
        if (L > mid) return query(rs, mid + 1, r, L, R);
        Info t = merge(t, query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
        return t;
    }
};