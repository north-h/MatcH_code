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


        return u;
    }
    void calc(Info &u, int add) {
        

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