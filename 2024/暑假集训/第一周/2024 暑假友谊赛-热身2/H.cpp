// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 600010;
const int INF = 0x3f3f3f3f;

using namespace std;

template<class T>
struct Seg {
    struct Node {int l, r; T add, mx;};
    vector<Node> tr; vector<T> a; int N;
    Seg(int n) { int N = n + 1; tr.resize(N * 4); a.resize(N); }
    Node merge(Node u, Node ls, Node rs) {
        u.mx = max(ls.mx, rs.mx);
        return u;
    }
    void calc(Node &u, int add) {
        u.mx = add;
    }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    void pushdown(int u) {
        auto [_, __, a, m] = tr[u];
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
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add);
        if (r > mid) modify(u << 1 | 1, l, r, add);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        pushup(u);
        return t;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    Seg<int> sg(N);
    sg.build(1, 1, N);
    int ans = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        int L = max(0ll, x - k);
        int R = min(N, x + k);
        // debug2(L, R);
        // debug1(sg.query(1, L, R).mx);
        sg.modify(1, x, x, sg.query(1, L, R).mx + 1);
        // for (int i = 1; i <= 12; i ++) {
        //     cout << sg.query(1, i, i).mx << ' ';
        // }
        // cout << "\n---------------\n";
    }
    cout << sg.query(1, 1, N).mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}