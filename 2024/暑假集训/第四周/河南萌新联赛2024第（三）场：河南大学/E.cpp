// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
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
        int op;
        T mx0, mx1;
        T lsum0, lsum1;
        T rsum0, rsum1;
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
        int lvl = l.r - l.l + 1;
        int rvl = r.r - r.l + 1;

        u.mx0 = max({l.mx0, r.mx0, l.rsum0 + r.lsum0});
        u.mx1 = max({l.mx1, r.mx1, l.rsum1 + r.lsum1});

        if (lvl == l.lsum0) u.lsum0 = l.lsum0 + r.lsum0;
        else u.lsum0 = l.lsum0;
        if (lvl == l.lsum1) u.lsum1 = l.lsum1 + r.lsum1;
        else u.lsum1 = l.lsum1;

        if (rvl == r.rsum0) u.rsum0 = l.rsum0 + r.rsum0;
        else u.rsum0 = r.rsum0;
        if (rvl == r.lsum1) u.rsum1 = l.rsum1 + r.rsum1;
        else u.rsum1 = r.rsum1;

        return u;
    }
    void calc(Info &u) {
        swap(u.mx0, u.mx1);
        swap(u.lsum0, u.lsum1);
        swap(u.rsum0, u.rsum1);
        u.op ^= 1;
    }
    void pushup(int u) {
        // debug1(u);
        tr[u] = merge(tr[u], tr[ls], tr[rs]);
    }
    void pushdown(int u) {
        auto [_, __, op, _1, _2, _3, _4, _5, _6] = tr[u];
        if (op) {
            calc(tr[ls]);
            calc(tr[rs]);
            tr[u].op ^= 1;
        }
    }
    void build(int u, int l, int r) {
        if (!a[l]) tr[u] = {l, r, 0, 1, 0, 1, 0, 1, 0};
        else tr[u] = {l, r, 0, 0, 1, 0, 1, 0, 1};
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

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        a[i] = 1;
    }
    SegmentTree<int> sg(a);
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            sg.modify(1, x, x);
        } else {
            int l, r; cin >> l >> r;
            cout << sg.query(1, l, r).mx1 << '\n';
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