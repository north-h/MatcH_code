struct info {
    int l, r, lazy;
};

info operator + (const info &ls, const info &rs) {
    info u;
    u.l = ls.l; u.r = rs.r;
    return u;
}

void apply(info &u, int lazy) {

}

template<class Info, class T>
struct SegmentTree {
    int n;
    vector<Info> tr;
    vector<T> a;
    SegmentTree(const vector<T> &init) {
        n = init.size();
        tr.assign(n * 4 + 1, Info());
        a = init;
        build(1, 1, n);
    }
    void pushup(int u) {
        tr[u] = tr[u << 1] + tr[u << 1 | 1];
    }
    void pushdown(int u) {
        ::apply(tr[u << 1], tr[u].lazy);
        ::apply(tr[u << 1 | 1], tr[u].lazy);
        tr[u].lazy = 0;
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0};
        if (l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            ::apply(tr[u], k);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Info query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Info t = query(u << 1, l, r) + query(u << 1 | 1, l, r);
        return t;
    }
};