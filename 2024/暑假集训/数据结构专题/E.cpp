// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m, p;

template<class T>
struct Seg {
    struct Node {int l, r; T add, mul, sum1, sum2;};
    vector<Node> tr; vector<T> a; int N;
    Seg(int n) { int N = n + 1; tr.resize(N * 4); a.resize(N); }
    Node merge(Node u, Node ls, Node rs) {
        u.sum2 = (ls.sum1 * rs.sum1 % p + ls.sum2 + rs.sum2) % p;
        u.sum1 = (ls.sum1 + rs.sum1) % p;
        return u;
    }
    void calc(Node &u, int add, int mul) {
        int lvl = u.r - u.l + 1;
        int mul2 = mul * mul % p;
        int add2 = add * add % p;
        if (lvl != 1) {
            int cnt = lvl * (lvl - 1) / 2;
            u.sum2 = u.sum2 * mul2 % p + (lvl - 1) * u.sum1 % p * add % p * mul % p + cnt % p * add2 % p;
            u.sum2 %= p;
        }
        u.sum1 = u.sum1 * mul % p + lvl * add % p;
        u.sum1 %= p;
        u.add = u.add * mul % p + add;
        u.add %= p;
        u.mul = u.mul * mul % p;
        u, mul %= p;
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
        tr[u] = {l, r, 0, 1, a[l], 0};
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

void solve() {
    cin >> n >> m >> p;
    Seg<int> seg(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> seg.a[i];
    }
    seg.build(1, 1, n);
    // for (int i = 1; i <= 9; i ++)
    //     cout << seg.tr[i].l << ' ' << seg.tr[i].r << ' ' << seg.tr[i].sum1 << ' ' << seg.tr[i].sum2 << '\n';
    // for (int i = 1; i <= n; i ++) cout << seg.query(1, i, i).sum1 << " \n"[i == n];
    // for (int i = 1; i <= n; i ++) cout << seg.query(1, i, i).sum2 << " \n"[i == n];
    // cout << seg.query(1, 1, n).sum2 << '\n';
    while (m --) {
        int op, l, r, v; cin >> op >> l >> r;
        if (op == 1) {
            cin >> v;
            seg.modify(1, l, r, v, 1);
        } else if (op == 2) {
            cin >> v;
            seg.modify(1, l, r, 0, v);
        } else cout << seg.query(1, l, r).sum2 << '\n';
        // cout << seg.query(1, 1, n).sum2 << '\n';
        // for (int i = 1; i <= 9; i ++)
        //     cout << seg.tr[i].l << ' ' << seg.tr[i].r << ' ' << seg.tr[i].sum1 << ' ' << seg.tr[i].sum2 << '\n';
        // for (int i = 1; i <= n; i ++) cout << seg.query(1, i, i).sum1 << " \n"[i == n];
        // for (int i = 1; i <= n; i ++) cout << seg.query(1, i, i).sum2 << " \n"[i == n];
        // cout << "------------------" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}