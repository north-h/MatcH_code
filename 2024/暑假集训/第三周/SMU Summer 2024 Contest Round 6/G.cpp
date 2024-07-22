// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct Seg {
#define lc u << 1
#define rc u << 1 | 1
    struct Node {
        int l, r;
        T lazy, mx0, mx1, l0, l1, r0, r1;
    };
    vector<Node> tr; vector<T> a; int n;
    Seg(int N) { n = N + 1; tr.resize(n * 4); a.resize(n); }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[lc], tr[rc]);
    }
    Node merge(Node t, Node l, Node r) {
        t.mx0 = max({l.mx0, r.mx0, l.r0 + r.l0});
        t.mx1 = max({l.mx1, r.mx1, l.r1 + r.l1});
        if (l.l0 == l.r - l.l + 1) t.l0 = l.l0 + r.l0;
        else t.l0 = l.l0;
        if (r.r0 == r.r - r.l + 1) t.r0 = l.r0 + r.r0;
        else t.r0 = r.r0;
        if (l.l1 == l.r - l.l + 1) t.l1 = l.l1 + r.l1;
        else t.l1 = l.l1;
        if (r.r1 == r.r - r.l + 1) t.r1 = l.r1 + r.r1;
        else t.r1 = r.r1;
        return t;
    }
    void calc(Node &u) {
        swap(u.l0, u.l1);
        swap(u.r0, u.r1);
        swap(u.mx0, u.mx1);
    }
    void pushdown(int u) {
        auto [_1, _2, lazy, _3, _4, _5, _6, _7, _8] = tr[u];
        if (lazy) calc(tr[lc]), tr[u].lazy ^= 1;
        if (lazy) calc(tr[rc]), tr[u].lazy ^= 1;
    }
    void build(int u, int l, int r) {
        if (a[l] == 1) {
            tr[u] = {l, r, 0, 0, 1, 0, 1, 0, 1};
        } else {
            tr[u] = {l, r, 0, 1, 0, 1, 0, 1, 0};
        }
        if (l >= r) return;
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            // calc(tr[u]);
            tr[u].lazy ^= 1;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(lc, l, r);
        if (r > mid) modify(rc, l, r);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(lc, l, r);
        if (l > mid) return query(rc, l, r);
        // Node lt = query(lc, l, r), rt = query(rc, l, r);
        Node t = merge(t, query(lc, l, r), query(rc, l, r));
        return t;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    Seg<int> sg(n + 1);
    for (int i = 0; i < s.size(); i ++) {
        sg.a[i + 1] = (s[i] == '1');
    }
    sg.build(1, 1, n);
    while (q --) {
        int c, l, r; cin >> c >> l >> r;
        if (c == 1) {
            sg.modify(1, l, r);
        } else {
            cout << sg.query(1, l, r).mx1 << '\n';
        }
        for (int i = 1; i <= n; i ++) {
            cout << sg.query(1, i, i).mx1 << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= n; i ++) {
            cout << sg.query(1, i, i).mx0 << ' ';
        }
        cout << '\n';
        cout << "---------------" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}