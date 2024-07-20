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
struct Seg {
    struct Node {int l, r; T add, sum1;};
    vector<Node> tr; vector<T> a; int N;
    Seg(int n) { int N = n + 1; tr.resize(N * 4); a.resize(N); }
    Node merge(Node u, Node ls, Node rs) {
        u.sum1 = ls.sum1 + rs.sum1;
        return u;
    }
    void calc(Node &u, int add) {
        if (!add) return ;
        u.sum1 = add;
        u.add = add;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        auto [_, __, a, ___] = tr[u];
        calc(tr[u << 1], a);
        calc(tr[u << 1 | 1], a);
        tr[u].add = 0;
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, a[l]};
        if (l == r) return ;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T add) {
        if (tr[u].l >= l && tr[u].r <= r) {
            calc(tr[u], add);
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add);
        if (r > mid) modify(u << 1 | 1, l, r, add);
        pushup(u);
    }
    void modify1(int u, int l, int r, T add) {
        // debug2(tr[u].l, tr[u].r);
        // debug2(l, r);
        bool k = tr[u].l >= l && tr[u].r <= r;
        // debug1(k);
        if (tr[u].l >= l && tr[u].r <= r) {
            // debug1(tr[u].sum1);
            // debug1(u);
            tr[u].sum1 += add;
            return ;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        // debug2(mid, l);
        if (l <= mid) modify1(u << 1, l, r, add);
        if (r > mid) modify1(u << 1 | 1, l, r, add);
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
    int n; cin >> n;
    Seg<int> sg(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> sg.a[i];
    }
    sg.build(1, 1, n);
    int Q; cin >> Q;
    while (Q --) {
        int op;
        cin >> op;
        if (op == 1) {
            int x; cin >> x;
            sg.modify(1, 1, n, x);
        } else if (op == 2) {
            int x, y; cin >> x >> y;
            // debug2(x, y);
            sg.modify1(1, x, x, y);
        } else {
            int x; cin >> x;
            cout << sg.query(1, x, x).sum1 << '\n';
        }
        // for (int i = 1; i <= n; i ++) {
        //     cout << sg.query(1, i, i).sum1 << ' ';
        // }
        // cout << "\n-------------\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}