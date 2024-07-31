template<class T>
struct SegmentTree {
#define ls u << 1
#define rs u << 1 | 1
    struct Info {
        int l, r;
    };
    vector<Info> tr;
    vector<T> a;
    SegmentTree(const vector<T> &init) {
        int n = init.size() - 1;
        tr.resize(n * 4 + 1);
        a = init;
        build(1, 1, n);
    }
    Info merge(Info &u, Info l, Info r) {


        return u;
    }
    void calc(Info &u) {

    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[ls], tr[rs]);
    }
    void pushdown(int u) {
        auto [_, __] = tr[u];
        if () {
            calc(tr[ls]);
            calc(tr[rs]);
        }
    }
    void build(int u, int l, int r) {
        if (!a[l]) tr[u] = {l, r};
        else tr[u] = {l, r};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            calc(tr[u]);
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(ls, l, r);
        if (r > mid) modify(rs, l, r);
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