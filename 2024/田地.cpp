// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;


template <class T>
struct Seg {
    struct Node { int l, r; T sum, add, lmx, rmx, mx; };
    vector<Node> tr; vector<T> a; int n;
    void init(int N) {
        n = N + 1;
        tr.resize(n * 4);
        a.resize(n);
    }
    void add(int x, T k) {
        a[x] = k;
    }
    Node merge(Node l, Node r) {
        Node t;
        t.sum = l.sum + r.sum;
        t.lmx = max(l.lmx, l.sum + r.lmx);
        t.rmx = max(r.rmx, l.rmx + r.sum);
        t.mx = max({l.mx, r.mx, l.rmx + r.lmx});
        return t;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        if (tr[u].add) {
            tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
            tr[u << 1 | 1].sum += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
            tr[u << 1].add += tr[u].add;
            tr[u << 1 | 1].add += tr[u].add;
            tr[u].add = 0;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, a[l], 0, a[l], a[l], a[l]};
        if (l == r) return ;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
            tr[u].add += k;
            tr[u].lmx = tr[u].rmx = tr[u].mx = k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        // debug2(l, r);
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, mid);
        if (l > mid) return query(u << 1 | 1, mid + 1, r);
        return merge(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    Seg<ll> sg; sg.init(n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sg.add(i, a[i]);
    }
    int m; cin >> m;
    sg.build(1, 1, n);
    // for (int i = 1; i <= 7; i ++) {
    //     cout << i << ":" << sg.tr[i].l << ' ' << sg.tr[i].r << ' ' << sg.tr[i].mx << ' ' << sg.tr[i].lmx << ' ' << sg.tr[i].rmx << '\n';
    // }
    // cout << sg.query(1, 1, 3) << '\n';
    while (m --) {
        int op; cin >> op;
        if (op == 0) {
            int x, y; cin >> x >> y;
            sg.modify(1, x, x, y - a[x]);
        } else {
            int l, r; cin >> l >> r;
            cout << sg.query(1, l, r).mx << '\n';
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     cout << sg.query(1, i, i) << ' ';
    // }
    cout << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}