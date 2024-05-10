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
    struct Node { int l, r; T lazy, mx, sum; };
    vector<Node> tr; vector<T> a, bit; int n;
    Seg(int N) { n = N; tr.resize(n * 4 + 1); a.resize(n + 1); bit.resize(n + 1); }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    Node merge(Node t, Node l, Node r) {
        t.mx = max(l.mx, r.mx);
        t.sum = l.sum + r.sum;
        return t;
    }
    void pushdown(int u) {
        if (tr[u].lazy) {
            tr[u << 1].mx = max(tr[u << 1].mx, tr[u].lazy);
            tr[u << 1].sum = (tr[u].r - tr[u].l + 1) * tr[u].lazy;
            tr[u << 1].lazy = tr[u].lazy;
            tr[u << 1 | 1].mx = max(tr[u << 1 | 1].mx, tr[u].lazy);
            tr[u << 1 | 1].sum = (tr[u].r - tr[u].l + 1) * tr[u].lazy;
            tr[u << 1 | 1].lazy = tr[u].lazy;
            tr[u].lazy = 0;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, bit[l] - 2 * a[l], a[l]};
        if (l == r) return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy = k;
            tr[u].mx = bit[l - 1] - k;
            tr[u].sum = (tr[u].r - tr[u].l + 1) * k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        return t;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    Seg<ll> sg(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> sg.a[i];
        sg.bit[i] = sg.bit[i - 1] + sg.a[i];
    }
    for (int i = 1; i <= n; i ++) cout << sg.a[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++) cout << sg.bit[i] << " \n"[i == n];
    sg.build(1, 1, n);
    for (int i = 1; i <= n; i ++) {
        cout << sg.query(1, i, i).sum << ' ';
    }
    cout << '\n';
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            sg.modify(1, x, x, y);
            for (int i = 1; i <= n; i ++) {
                cout << sg.query(1, i, i).sum << ' ';
            }
            cout << '\n';
        } else {
            int l, r; cin >> l >> r;
            cout << sg.query(1, l, r).mx - sg.query(1, 1, l - 1).sum << '\n';
        }
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}