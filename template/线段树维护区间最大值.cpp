template<class T>
struct Seg {
    struct Node {int l, r; T add, mul, mx;};
    vector<Node> tr; vector<T> a; int N;
    Seg(int n) { int N = n + 1; tr.resize(N * 4); a.resize(N); }
    Node merge(Node u, Node ls, Node rs) {
        u.mx = max(ls.mx, rs.mx);
        return u;
    }
    void calc(Node &u, int add, int mul) {
        int lvl = u.r - u.l + 1;
        u.mx = u.mx * mul + lvl * add;
        u.add = u.add * mul + add;
        u.mul = u.mul * mul;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        auto [_, __, a, m, _1, _2] = tr[u];
        calc(tr[u << 1], a, m);
        calc(tr[u << 1 | 1], a, m);
        tr[u].mul = 1;
        tr[u].add = 0;
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 1, a[l]};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T add, T mul) {
        if (tr[u].l >= l && tr[u].r <= r) {
            calc(tr[u], add, mul);
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add, mul);
        if (r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        pushup(u);
        return t;
    }
};
